#pragma once

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

    Capsule(vec3 points[2], float radius) : radius{radius}, points{points[0], points[1]} {}
};




