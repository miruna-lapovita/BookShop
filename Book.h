//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_BOOK_H
#define LAB_11_12OOP_BOOK_H
#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    int id;
    string title;
    int price;
public:
    Book();//constructor implicit
    Book(int newId, string newTitle, int newPrice);//constructor cu parametri
    Book(const Book& entity);//constructor de copiere
    ~Book() = default;//destructor
    int getId();//getter id
    string getTitle();//getter title
    int getPrice();//getter price;
    void setId(int newId);//setter id
    void setTitle(string newTitle);//setter title
    void setPrice(int newPrice);//setter price
    Book& operator=(const Book& entity);//operator de atribuire
    bool operator==(const Book& entity) const;//operator egal
    bool operator <(const Book& entity) const;//operator <
    //string toString();//transforma in string
    friend ostream& operator<<(ostream& os, const Book& entity);
    friend istream& operator>>(istream& is,  Book& entity);
};


#endif //LAB_11_12OOP_BOOK_H
