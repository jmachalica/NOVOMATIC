#ifndef NOVOMATIC_DELETIONOFELEMENTS_H

#include <vector>

template<typename T>
void deleteItem(std::vector<T> &vec, size_t index) {

    size_t size = vec.size();

    if (!size || index > size - 1 || index < 0) return; // size and index validation

    if (index != size - 1) // if not last element
    {
        vec[index] = vec.back();  // insert last element into index position
    }

    vec.pop_back(); // delete last element

}

template<typename T>
void printVec(std::vector<T> &vec) {
    size_t size = vec.size();
    for (int i{0}; i < size; i++) {

        std::cout << vec[i] << " ";

    }

    std::cout << std::endl;

}


#define NOVOMATIC_DELETIONOFELEMENTS_H

#endif //NOVOMATIC_DELETIONOFELEMENTS_H
