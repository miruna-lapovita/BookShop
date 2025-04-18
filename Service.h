//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_SERVICE_H
#define LAB_11_12OOP_SERVICE_H
#include "Repository.h"
#include "RepositoryFile.h"
#include "Bancnote.h"
#include "Book.h"

class Service {
private:
    RepositoryFile<Book> EntityRepo;
    RepositoryFile<Bancnote> BancnoteRepo;
public:
    //constructor implicit
    Service();
    //constructor cu parametri
    Service(RepositoryFile<Book> &entityRepo, RepositoryFile<Bancnote> &bancnoteRepo);
    ~Service() = default;
    //operatii CRUD
    void add(int, string, int);
    void addBancnote(int tip, int valoare);
    void remove(int, string, int);
    void deleteBancnote(int tip, int valoare);
    void update(int, string, int, int, string, int);
    void updateBancnote(int tip, int valoare);
    int find(int, string, int);
    vector<Book> getAll();
    //functionalitati + aux
    vector<Book> filterByPrice();
    Book getTopBook();
    int size();
};


#endif //LAB_11_12OOP_SERVICE_H
