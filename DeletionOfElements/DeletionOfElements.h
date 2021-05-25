#pragma once

#include <vector>

template<typename T>
void deleteItem(std::vector<T> &vec, int index) {
    size_t size = vec.size();

    // size and index validation
    if (!size) {
        throw std::length_error("Vector is empty.");
    }

    if (index > size - 1 || index < 0) {
        throw std::out_of_range("Index "+std::to_string(index)+  " is out of range.");
    }


    if (index != size - 1) // if not last element
    {
        vec[index] = vec.back();  // insert last element into index position
    }

    vec.pop_back(); // delete last element

}


template<typename T>
void printVec(std::vector<T> &vec) {

    for (T &element:vec) {
        std::cout << element << " ";
    }

    std::cout << std::endl;

}



