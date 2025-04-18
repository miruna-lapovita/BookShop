//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_ELEMENTNOTFOUNDEXCEPTION_H
#define LAB_11_12OOP_ELEMENTNOTFOUNDEXCEPTION_H

#include <stdexcept>

class ElementNotFoundException:
        public std::runtime_error{
private:
    char* message;
public:
    ElementNotFoundException(char* msg):
        std::runtime_error(msg), message(msg){
    }
    char* what(){
        return message;
    }
};
#endif //LAB_11_12OOP_ELEMENTNOTFOUNDEXCEPTION_H
