//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_INVALIDCODEEXCEPTION_H
#define LAB_11_12OOP_INVALIDCODEEXCEPTION_H

#include <iostream>
#include <stdexcept>

using namespace std;


class InvalidCodeException : public invalid_argument {
private:
    char* message;
public:
    InvalidCodeException(char* msg): invalid_argument(msg), message(msg) {}
    char* what() {
        return message;
    }
};

#endif //LAB_11_12OOP_INVALIDCODEEXCEPTION_H
