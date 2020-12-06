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
        for (auto i = image_width - 1; i >= 0; --i)
        {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = .25;

            auto ir = static_cast<int>(255.99 * r);
            auto ig = static_cast<int>(255.99 * g);
            auto ib = static_cast<int>(255.99 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}