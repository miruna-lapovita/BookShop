//
// Created by Miruna on 5/17/2024.
//

#include "Bancnote.h"
#include <iostream>
#include <string>

Bancnote::Bancnote() {//constructor implicit
    this -> valoare = -1;
    this -> tip = 0;
}
//constructor cu parametri
Bancnote::Bancnote(int valoare, int tip): valoare(valoare), tip(tip) {}

//getter valoare
int Bancnote::get_valoare() const {
    return valoare;
}

//getter tip
int Bancnote::get_tip() const {
    return tip;
}

//setter valoare
void Bancnote::set_valoare(int valoare) {
    this -> valoare = valoare;
}

//setter tip
void Bancnote::set_tip(int tip) {
    this -> tip = tip;
}

//operator <
bool Bancnote::operator<(const Bancnote &bancnote) const {
    return valoare < bancnote.valoare;
}

//operator egalitate
bool Bancnote::operator==(const Bancnote &bancnote) const {
    return (this -> valoare == bancnote.valoare && this -> tip == bancnote.tip);
}

//permite sa inmultim un intreg obiect bancnota cu un scalar intreg
Bancnote Bancnote::operator*(int scalar) const {
    return Bancnote(valoare * scalar, tip);
}

//supraincarcarea operatorului de scriere
ostream &operator<<(ostream &os, const Bancnote &bancnote) {
    os << bancnote.tip << " " << bancnote.valoare;
    return os;
}

//supraincarcarea operatorului de citire
istream &operator>>(istream &is, Bancnote &bancnote) {
    is >> bancnote.tip >> bancnote.valoare;
    return is;
}




