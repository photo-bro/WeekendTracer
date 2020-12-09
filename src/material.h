#pragma once

#include "common.h"

struct hit_record;

class material {
   public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attentuation,
                         ray& scattered) const = 0;
    virtual ~material() = default;
};

class lambertian : public material {
   public:
    lambertian(const color& a) : albedo(a) {}
    virtual ~lambertian() = default;

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attentuation,
                         ray& scattered) const override {
        (void)r_in;
        auto scatter_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero()) {
            scatter_direction = rec.normal;
        }

        scattered = ray(rec.p, scatter_direction);
        attentuation = albedo;
        return true;
    }

   public:
    color albedo;
};

class metal : public material {
   public:
    metal(const color& a, double f) : albedo(a), fuzz(f) {}
    virtual ~metal() = default;

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation,
                         ray& scattered) const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

   public:
    color albedo;
    double fuzz;
};