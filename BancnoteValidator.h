//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_BANCNOTEVALIDATOR_H
#define LAB_11_12OOP_BANCNOTEVALIDATOR_H

#include "InvalidCodeException.h"

class BancnoteValidator {
private:
    int firstValidValue;
    int secondValidValue;
    int thirdValidValue;
public:
    BancnoteValidator(int firstValue, int secondValue, int thirdValue):
            firstValidValue(firstValue),
            secondValidValue(secondValue),
            thirdValidValue(thirdValue) {}
    void validate(int value) const {
        if (value != firstValidValue && value != secondValidValue && value != thirdValidValue) {
            throw InvalidCodeException("Enter a valid value!!");
        }
    }


};
#endif //LAB_11_12OOP_BANCNOTEVALIDATOR_H
