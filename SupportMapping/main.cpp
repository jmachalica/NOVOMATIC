#include <iostream>
#include "SupportMapping.h"

int main() {

    std::cout << "Support Mapping" << std::endl;

    vec3 map_vec{4, 2, 1};
    std::cout << "Vector: " << map_vec<<std::endl;

    //sphere
    try {
        std::cout << "Sphere" << std::endl;
        vec3 mapping = support(map_vec, Sphere(vec3(1, 3, 10), 10));
        std::cout<<"Support point: " << mapping << std::endl;
    }
    catch (std::exception &e) {

        std::cout << e.what() << std::endl;
    }

    //aabb
    try {
        std::cout << "Aabb" << std::endl;
        vec3 mapping = support(map_vec, Aabb(vec3(10, 3, 10), vec3(20, 8, 14)));
        std::cout <<"Support point: "<< mapping << std::endl;
    }
    catch (std::exception &e) {

        std::cout << e.what() << std::endl;
    }

    //Tetrahendron
    try {

        std::cout << "Tetrahendron" << std::endl;
        vec3 points_tetra[4]{vec3(1, 2, 3), vec3(-2, -11, 20), vec3(5, -7, 8), vec3(0, 5, 3)};
        vec3 mapping = support(map_vec, Tetrahedron(points_tetra));
        std::cout <<"Support point: "<< mapping << std::endl;
    }
    catch (std::exception &e) {

        std::cout << e.what() << std::endl;
    }


    //capsule
    try {
        std::cout << "Capsule" << std::endl;
        vec3 points[2]{vec3(-5, -5, -5), vec3(11, 12, 13)};
        Capsule cap(points, 5);
        vec3 mapping = support(map_vec, cap);
        std::cout<<"Support point: " << mapping << std::endl;
    }
    catch (std::exception &e) {

        std::cout << e.what() << std::endl;
    }


    return 0;
}
