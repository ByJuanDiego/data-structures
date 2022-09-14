//
// Created by Juan Diego on 9/12/2022.
//

#ifndef TREES_ALUMNO_H
#define TREES_ALUMNO_H

#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::ostream;

struct Alumno{
    string nombre;
    int edad;

    Alumno(): edad(0){};
    Alumno(string nombre, int edad)
            : nombre(std::move(nombre)), edad(edad){}
    explicit Alumno(string nombre)
            : nombre(std::move(nombre)), edad(0){}

    [[nodiscard]] bool operator < (const Alumno& other) const{
        return nombre < other.nombre;
    }
    [[nodiscard]] bool operator > (const Alumno& other) const{
        return nombre > other.nombre;
    }

    [[nodiscard]] bool operator == (const Alumno& other) const{
        return nombre == other.nombre;
    }

    friend ostream& operator<< (ostream& os, const Alumno& other){
        os << other.nombre << ", " << other.edad;
        return os;
    }
};

#endif //TREES_ALUMNO_H
