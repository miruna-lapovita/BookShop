//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_UI_H
#define LAB_11_12OOP_UI_H

#include "Service.h"

class UI{
private:
    Service service;
    void add();
    void remove();
    void update();
    void find();
    void getAll();
public:
    UI();
    explicit UI(Service &);
    ~UI();
    void adminMenu();
    void userMenu();
    void menu();
    void filterByPrice();
    void topBook();
};

#endif //LAB_11_12OOP_UI_H
