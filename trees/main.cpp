#include <iostream>
#include <string>
#include <utility>
#include "BSTree/binary_search_tree.h"
using std::cout;
using std::endl;
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

int main() {
    binary_search_tree<Alumno> tree;
    tree.insert(Alumno("Juan Diego", 19));
    tree.insert(Alumno("Fernando", 20));
    tree.insert(Alumno("Heider", 18));
    tree.insert(Alumno("Carlos", 23));
    tree.inorder([](const Alumno& alumno){cout << alumno << endl;});
    cout << tree.find(Alumno("Juan Diego")) << endl;
    return 0;
}
