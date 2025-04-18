//
// Created by Miruna on 5/17/2024.
//

#ifndef LAB_11_12OOP_BANCNOTE_H
#define LAB_11_12OOP_BANCNOTE_H

#include <ostream>
#include <istream>
using namespace std;

class Bancnote {
private:
    int valoare;
    int tip;
public:
    //constructor implicit
    Bancnote();

    //constructor cu parametri
    Bancnote(int valoare, int tip);

    //destructor
    ~Bancnote() = default;

    //getter valoare
    [[nodiscard]] int get_valoare() const;

    //getter tip
    [[nodiscard]] int get_tip() const;

    //setter valoare
    void set_valoare(int valoare);

    //setter tip
    void set_tip(int tip);

    //operatori
    bool operator<(const Bancnote& bancnote) const;
    bool operator==(const Bancnote& bancnote) const;

    //suprascriem * ca sa putem inmulti un obiect bancnote cu scalar intreg
    Bancnote operator *(int scalar) const;

    //pot accesa membri privati ai clasei, suprascriere in fluxul de intrare si de iesire
    friend ostream& operator<<(ostream& os, const Bancnote& bancnote);
    friend istream& operator>>(istream &is, Bancnote &bancnote);
};

#endif //LAB_11_12OOP_BANCNOTE_H
