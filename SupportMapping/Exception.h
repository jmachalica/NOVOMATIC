#pragma once

#include <exception>

struct Exception : public std::exception {

    explicit Exception(std::string message = "") {
        this->message.append(message);
    }

    const char *what() const noexcept override {
        return message.c_str();
    }

    std::string message{"Error: "};


};


struct VectorZero : Exception {
    VectorZero(std::string message = "") : Exception("Vector length is 0." + message) {}

};




