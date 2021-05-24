#ifndef NOVOMATIC_SUPPORTMAPPING_H
#define NOVOMATIC_SUPPORTMAPPING_H
#include "vec3.h"

///////////////// Objects
struct Sphere {
    vec3 center;
    float radius;

    Sphere(vec3 center, float radius) : center{center}, radius{radius} {}

};

// Axis-aligned bounding box. Cube with edges aligned to x,y,z axis.
struct Aabb {
    vec3 min{};
    vec3 max{};

    Aabb(vec3 min, vec3 max) : min{min}, max{max} {}
};

// Triangular pyramid.
struct Tetrahedron {
    vec3 points[4]{};

    Tetrahedron(vec3 points[4]) : points{points[0], points[1], points[2], points[3]} {}

};

// Cylinder with hemispherical ends.
struct Capsule {
    vec3 points[2]{};
    float radius;

    Capsule(vec3 points[2], float radius) : radius{radius}, points{points[0], points[1]} {};
};


// Support mapping function implementation
template<typename Shape>
vec3 support(vec3 v, Shape s);


template<>
vec3 support<Sphere>(vec3 v, Sphere sphere) {
    return v.normalize() * sphere.radius + sphere.center;
};

template<>
vec3 support<Capsule>(vec3 v, Capsule c) {

    //central point of capsule
    vec3 capsule_center = center(c.points[0], c.points[1]);

    //support point of the sphere made from capsule by removing cylinder, with center at capsule center
    vec3 point = support(v, Sphere(capsule_center, c.radius));

    // how should the center of sphere be moved to points[0], opposite to points[1]
    vec3 translation = c.points[0] - capsule_center;

    float dot_dir = point * translation;

    // checking on which side of capsule is point and translating
    if (dot_dir >= 0) {
        point = point + translation;
    } else {
        point = point - translation;
    }
    return point;


};

template<>
vec3 support<Aabb>(vec3 v, Aabb aabb) {

    //aabb center
    vec3 aabb_center = center(aabb.min, aabb.max);

    vec3 shape = aabb.max - aabb_center;  //half aabb size in each direction

    //checking direction of vector and multiplying by half-length in each direction, then translation
    return vec3(sign(v.x) * shape.x, sign(v.y) * shape.y, sign(v.z) * shape.z) + aabb_center;

};


template<>
vec3 support<Tetrahedron>(vec3 v, Tetrahedron tetra) {

    //iteratively checking which point gives max dot product with v

    vec3 max_dot_vec{tetra.points[0]};
    float max_dot{tetra.points[0] * v};

    for (int i = 1; i <= 3; i++) {

        float dot = tetra.points[i] * v;

        if (max_dot < dot) {

            max_dot_vec = tetra.points[i];
            max_dot = dot;
        }

    }
    return max_dot_vec;

};


#endif //NOVOMATIC_SUPPORTMAPPING_H
