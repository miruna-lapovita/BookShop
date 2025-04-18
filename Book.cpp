//
// Created by Miruna on 5/17/2024.
//


#include "Book.h"
#include <iostream>
#include <cstring>

Book::Book() {//constructor implicit
    id = -1;
    title = "";
    price = -1;
}
//constructor cu parametri
Book::Book(int newId, string newTitle, int newPrice) {
    this -> id = newId;
    this -> price = newPrice;
    this -> title = newTitle;
}

Book::Book(const Book &entity) {//constructor de copiere
    this -> id = entity.id;
    this -> title = entity.title;
    this -> price = entity.price;
}

int Book::getId() {//getter id
    return this -> id;
}

string Book::getTitle() {//getter title
    return this -> title;
}

int Book::getPrice() {//getter pret
    return this -> price;
}

void Book::setId(int newId) {//setter id
    this -> id = newId;

}

void Book::setTitle(string newTitle) {//setter title
    this -> title = newTitle;

}

void Book::setPrice(int newPrice) {// setter price
    this -> price = newPrice;

}

Book &Book::operator=(const Book &entity) {
    this -> id = entity.id;
    this -> title = entity.title;
    this -> price = entity.price;
    return *this;
}

bool Book::operator==(const Book &entity) const {//operator ==
    return (this -> id == entity.id && this -> title == entity.title && this -> price == entity.price);
}

bool Book::operator<(const Book &entity) const {
    return(this -> price < entity.price);
}

ostream &operator<<(ostream &os, const Book &entity) {
    os << entity.id << " " << entity.title << " " << entity.price;
    return os;
}

istream &operator>>(istream &is, Book &entity) {
    is >> entity.id >> entity.title >> entity.price;
    return is;
}

