#include "color.h"
#include "vec3.h"
#include <iostream>

int main()
{
    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    std::cout << "P3\n"
              << image_width << ' ' << image_height << "\n255\n"
              << std::endl;

    for (auto j = image_height - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (auto i = image_width - 1; i >= 0; --i)
        {
            color pixel_color(double(i) / (image_width - 1),
                              double(j) / (image_height - 1),
                              0.25);
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
}