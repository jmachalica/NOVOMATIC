#ifndef NOVOMATIC_EXCEPTION_H
#define NOVOMATIC_EXCEPTION_H

#include <exception>
struct Exception : public std::exception {

    explicit Exception(const char *message = "") {
        this->message.append(message);

    }

    const char *what() const noexcept override {
        return message.c_str();
    }

    std::string message{"Error: "};


};


#endif //NOVOMATIC_EXCEPTION_H
