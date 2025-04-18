//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_REPOSITORY_H
#define LAB_11_12OOP_REPOSITORY_H
#include <vector>
#include <algorithm>
#include "Book.h"
#include "ElementNotFoundException.h"
using namespace std;

template <typename T>
class Repository{
private:
    vector<T> entities;
public:
    Repository();//constructor
    ~Repository() = default;//destructor

    //operatii CRUD
    virtual void addEntity(T&);

    virtual void deleteEntity(T&);

    virtual void updateEntity(T&, T&);
    vector<T> getAll();
    int getSize();
    int findEntity(T&);

};

///IMPLEMENTARI
template<typename T>
int Repository<T>::findEntity(T& entity) {
    for(int i = 0; i < entities.size(); i++){//iteram pri  vectorul de entitati
        if((entities[i]) == entity){// cand se egaleaza cu entity, o gaseste in vector si returneaza indicele
            return i;
        }
    }
    return -1;
}

template<typename T>
int Repository<T>::getSize() {
    return entities.size();
}

template<typename T>
vector<T> Repository<T>::getAll() {
    return entities;
}

template<typename T>
void Repository<T>::updateEntity(T & entity, T& newEntity) {
    int index = findEntity(entity);//verifica daca entitatea exista in vector
    if(index != -1){//daca a gasit-o, pune noua entitate la indexul gasit
        entities[index] = newEntity;
    }

}

template<typename T>
void Repository<T>::deleteEntity(T &entity) {
    if (findEntity(entity) == -1){
        throw ElementNotFoundException("The element doesn't exist!!!!!");
    }
    typename vector<T>::iterator it;//declaram un iterator pentru a itera prin vector
    it = find(entities.begin(), entities.end(), entity);
    if(it != entities.end()){//daca iteratorul nu a ajuns la final, adica a gasit entitatea in vector
        entities.erase(it);//se sterge
    }


}

template<typename T>
void Repository<T>::addEntity(T& entity) {
    entities.push_back(entity);

}


template<typename T>
Repository<T>::Repository() {}


#endif //LAB_11_12OOP_REPOSITORY_H
