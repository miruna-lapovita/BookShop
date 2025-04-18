//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_ENTITYVALIDATOR_H
#define LAB_11_12OOP_ENTITYVALIDATOR_H

#include "InvalidCodeException.h"

class EntityValidator{
private:
    int validId;
public:
    EntityValidator(int id) : validId(id) {}
    void validate (int id) {
        if (id < validId) {
            throw InvalidCodeException("Not a valid id!!!Try something else, please...");
        }
    }
};
#endif //LAB_11_12OOP_ENTITYVALIDATOR_H
