//
// Created by Miruna on 5/17/2024.
//
#include <cassert>
#include "Tests.h"
#include "Book.h"
#include "Repository.h"
#include "Service.h"
#include <iostream>
#include <string>

void tests(){
    entityTests();
    repoTests();
    serviceTests();
    bancnoteServiceTest();
};

void entityTests(){
    Book entity1 = Book(1, "book1", 30);
    Book entity2 = Book(2, "book2", 35);
    assert(entity1.getId() == 1);
    assert(entity2.getTitle() == "book2");
    assert(entity1.getPrice() == 30);
    entity1.setTitle("setTitle");
    assert(entity1.getTitle() == "setTitle");
    entity2.setId(3);
    assert(entity2.getId() == 3);
    entity1.setPrice(50);
    assert(entity1.getPrice() == 50);
    assert(entity1.getTitle() == "setTitle");
    entity1.setId(3);
    assert(entity1.getId() == 3);
    //assert(entity1 == entity2);
    Book entity3 = Book(2, "aaaa", 20);
    assert(entity3 < entity1);
    cout << "All good with the entity!!!" << endl;
}

void repoTests(){
    RepositoryFile<Book> repo("C:\\Users\\Miruna\\CLionProjects\\Lab9-10OOP\\test.txt");

    //add test
    Book b1(1, "book1", 30);
    repo.addEntity(b1);
    assert(repo.getSize() == 1);

    //find test
    Book b2(2, "book2", 40);
    repo.addEntity(b2);
    assert(repo.findEntity(b2) == 1);

    //update test
    Book b2_update(2, "newBook2", 50);
    repo.updateEntity(b2, b2_update);
    assert(repo.getAll()[1] == b2_update);

    //delete test
    repo.deleteEntity(b1);
    assert(repo.getSize() == 1);
    assert(repo.findEntity(b1) == -1);

    //test getAll
    vector<Book> entities = repo.getAll();
    assert(entities.size() == 1);
    assert(entities[0] == b2_update);
    cout << "All good in repo!!" << endl;
}

void serviceTests(){
    RepositoryFile<Book> entity("C:\\Users\\Miruna\\CLionProjects\\Lab9-10OOP\\testService.txt");
    RepositoryFile<Bancnote> bancnote("C:\\Users\\Miruna\\CLionProjects\\Lab9-10OOP\\testService.txt");
    Service service(entity, bancnote);

    //add test
    service.add(1, "bookTitle", 70);
    assert(service.size() == 1);

    //find test
    assert(service.find(1, "bookTitle", 70) == 0);

    //update test
    service.update(1, "bookTitle", 70, 2, "bookTitle2", 80);
    assert(service.getAll()[0].getId() == 2);

    //delete test
    service.remove(2, "bookTitle2", 80);
    assert(service.size() == 0);

    service.add(1, "bookTitle", 70);
    service.add(2, "bookTitle2", 50);
    vector<Book> sortEntities = service.filterByPrice();
    assert(sortEntities[0].getId() == 2);
}

void bancnoteServiceTest(){
    RepositoryFile<Book> entity("C:\\Users\\Miruna\\CLionProjects\\Lab9-10OOP\\testService.txt");
    RepositoryFile<Bancnote> bancnote("C:\\Users\\Miruna\\CLionProjects\\Lab9-10OOP\\bancnoteServiceTest.txt");

    Service service(entity, bancnote);
    service.addBancnote(1, 10);
    service.addBancnote(5, 20);
    service.addBancnote(10, 80);
    service.deleteBancnote(5, 20);

    cout << "All good in money service!!"<< endl;
}