#pragma once

#include "vec3.h"
#include "Shapes.h"
#include "Exception.h"
// Support mapping function implementation
// Template specialization due to task specification
// Shape passed by value due to task specification

template<typename Shape>
vec3 support(vec3 v, Shape s);

template<>
vec3 support<Sphere>(vec3 v, Sphere sphere) {
    if (v.isZeroVector())throw VectorZero("Support can't be calculated");
    return v.normalize() * sphere.radius + sphere.center;
};

template<>
vec3 support<Capsule>(vec3 v, Capsule c) {


    if (v.isZeroVector())throw VectorZero("Support can't be calculated");
    //central point of capsule
    vec3 capsule_center = center(c.points[0], c.points[1]);

    //support point of the sphere made from capsule by removing cylinder, with center at capsule_center
    vec3 point = support(v, Sphere(capsule_center, c.radius));

    // how should the center of sphere be moved to points[0], opposite direction to points[1] -> translation of support point
    vec3 translation = c.points[0] - capsule_center;

    vec3 point_1 = point + translation;
    vec3 point_2 = point - translation;

    //choosing between 2 points
    if (point_1 * v >= point_2 * v)return point_1;
    else return point_2;


};

template<>
vec3 support<Aabb>(vec3 v, Aabb aabb) {
    if (v.isZeroVector())throw VectorZero("Support can't be calculated");

    //aabb center
    vec3 aabb_center = center(aabb.min, aabb.max);

    //half size of Aabb in each direction
    vec3 half_size = (aabb.max - aabb.min).vec_abs() / 2;
    //checking direction of vector and multiplying by half-size in each direction, then translation
    return vec3(sign(v.x) * half_size.x, sign(v.y) * half_size.y, sign(v.z) * half_size.z) + aabb_center;

};


template<>
vec3 support<Tetrahedron>(vec3 v, Tetrahedron tetra) {

    if (v.isZeroVector())throw VectorZero("Support can't be calculated");
    //iteratively checking which point gives max dot product with v, since result can be only one of these points

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

