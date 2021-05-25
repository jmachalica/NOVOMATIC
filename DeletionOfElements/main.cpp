#include <iostream>
#include "DeletionOfElements.h"
#include <vector>

int main() {

    std::cout << "Deleting Elements in constant time" << std::endl;
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    printVec(vec);

    try {
        deleteItem(vec, 0);
        printVec(vec);
    } catch (std::exception &e) {
        std::cerr << e.what()<< "Element can't be deleted" << std::endl;
    }


    try {
        deleteItem(vec, 3);
        printVec(vec);
    } catch (std::exception &e) {
        std::cerr << e.what()<< "Element can't be deleted" << std::endl;
    }

    try {
        deleteItem(vec, 5);
        printVec(vec);
    } catch (std::exception &e) {
        std::cerr << e.what()<< "Element can't be deleted" << std::endl;
    }

    try {
        deleteItem(vec, -1);
        printVec(vec);
    } catch (std::exception &e) {
        std::cerr << e.what()<< "Element can't be deleted" << std::endl;
    }

    try {
        deleteItem(vec, 7);
        printVec(vec);
    } catch (std::exception &e) {
        std::cerr << e.what()<< "Element can't be deleted" << std::endl;
    }

    return 0;
}
