#include <iostream>
#include "DeletionOfElements.h"
#include <vector>

int main() {

    std::cout << "Deleting Elements in constant time" << std::endl;
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7};
    printVec(vec);
    deleteItem(vec, 7);
    printVec(vec);
    deleteItem(vec, 0);
    printVec(vec);
    deleteItem(vec, 2);
    printVec(vec);

    return 0;
}
