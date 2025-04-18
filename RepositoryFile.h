//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_REPOSITORYFILE_H
#define LAB_11_12OOP_REPOSITORYFILE_H
#include <fstream>
#include "Repository.h"

using namespace std;

template <typename T>
class RepositoryFile: public Repository<T>{
protected:
    string fileName;
public:
    //constructor implicit
    RepositoryFile():Repository<T>(){}
    //constructor cu parametru
    explicit RepositoryFile<T>(string fileName): fileName(fileName){};
    //citire si afisare din fisier
    void loadFromFile();
    void saveToFile();
    //operatii
    void addEntity(T& entity){
        Repository<T>::addEntity(entity);
        saveToFile();
    }
    void deleteEntity(T& entity){
        Repository<T>::deleteEntity(entity);
        saveToFile();
    }
    void updateEntity(T& entity, T& newEntity){
        Repository<T>::updateEntity(entity, newEntity);
        saveToFile();
    }
    //citire si afisare din fisier


};

template<typename T>
void RepositoryFile<T>::saveToFile() {
    ofstream f(fileName, ios::out);
    if(!f.is_open()){
        cerr << "Eroare la deschiderea fisierului " << fileName << "!" << endl;
        return;
    }
    vector<T> entities = Repository<T>::getAll();
    for (auto it : entities){
        f << it << "\n";
        f.flush(); //?????
    }
    f.close();

}

template<typename T>
void RepositoryFile<T>::loadFromFile() {
    ifstream f(fileName );
    if(!f.is_open()){
        cerr << "Eroare la deschiderea fisierului " << fileName << "!" << endl;
        return;
    }
    vector<T> entities = Repository<T>::getAll();
    for(auto ent: entities){
        Repository<T>::deleteEntity(ent);
    }
    T entity;
    while(f >> entity){
        Repository<T>::addEntity(entity);
    }
    f.close();

}


#endif //LAB_11_12OOP_REPOSITORYFILE_H
