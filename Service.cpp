//
// Created by Miruna on 5/17/2024.
//

#include "Service.h"
#include "Book.h"
#include "RepositoryFile.h"
#include "BancnoteValidator.h"
#include "EntityValidator.h"
#include <iostream>
#include <string>

//constructor implicit
Service::Service() {}

//constructor cu parametri
Service::Service(RepositoryFile<Book> &entityRepo, RepositoryFile<Bancnote> &bancnoteRepo): EntityRepo(entityRepo), BancnoteRepo(bancnoteRepo) {}

void Service::add(int id, string title, int price) {
    try {
        Book entity(id, title, price);
        EntityValidator val(EntityRepo.getSize());
        val.validate(entity.getId());
        EntityRepo.addEntity(entity);
    }catch (InvalidCodeException &e){
        cout << "Exception: " << e.what() << endl;
    }
}

//operatii CRUD

void Service::addBancnote(int tip, int valoare) {
    try {
        Bancnote bancnota(valoare, tip);
        BancnoteValidator val(1, 5, 10);
        val.validate(tip);
        BancnoteRepo.addEntity(bancnota);
    }catch (InvalidCodeException &e){
        cout << "Exception: " << e.what() << endl;
    }

}

void Service::remove(int id, string title, int price) {
    try {
        Book entity(id, title, price);
        cout << EntityRepo.findEntity(entity) << endl;
        if (EntityRepo.findEntity(entity) == -1) {
            cout << EntityRepo.findEntity(entity);
            throw ElementNotFoundException("The product wasn't found!!");
        }

        EntityRepo.deleteEntity(entity);
    }catch (ElementNotFoundException &e){
        cout << "Exception: " << e.what() << endl;
    }
}



void Service::deleteBancnote(int tip, int valoare) {
    try {
        Bancnote bancnota(valoare, tip);
        BancnoteRepo.loadFromFile();
        if (BancnoteRepo.findEntity(bancnota) == -1) {
            throw ElementNotFoundException("The money wasn't found!!");
        }
        BancnoteRepo.deleteEntity(bancnota);
    }catch (ElementNotFoundException &e){
        cout << "Exception: " << e.what() << endl;
    }
}

void Service::update(int id, string title, int price, int newId, string newTitle, int newPrice) {
    Book book(id, title, price);
    Book newBook(newId, newTitle, newPrice);
    if(EntityRepo.findEntity(book) == -1){
        throw ElementNotFoundException("The product wasn't found!!");
    }
    EntityRepo.updateEntity(book, newBook);


}

void Service::updateBancnote(int tip, int valoare) {
    BancnoteRepo.loadFromFile();
    Bancnote bancnota(valoare, tip);
    Bancnote newBancnota(bancnota.get_valoare() + valoare, tip);
    BancnoteRepo.updateEntity(bancnota, newBancnota);
}

int Service::find(int id, string title, int price) {
    Book book(id, title, price);
    EntityRepo.loadFromFile();
    return EntityRepo.findEntity(book);

}

vector<Book> Service::getAll() {
    EntityRepo.loadFromFile();
    return EntityRepo.getAll();
}

vector<Book> Service::filterByPrice() {
    vector<Book> sortEntities;
    vector<Book> entities = EntityRepo.getAll();
    sort(entities.begin(), entities.end());
    for (auto entity: entities){
        sortEntities.push_back(entity);
    }
    return sortEntities;
}

int Service::size() {
    EntityRepo.loadFromFile();
    return EntityRepo.getSize();
}

Book Service::getTopBook() {
    vector<Book> topBook;
    topBook = filterByPrice();
    int n = EntityRepo.getSize();
    return topBook[n - 1];
}







