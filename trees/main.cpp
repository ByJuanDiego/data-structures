#include <iostream>
#include <string>
#include <utility>
#include "BSTree/binary_search_tree.h"
#include "alumno.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

int main() {
    binary_search_tree<Alumno> tree;
    tree.insert(Alumno("Juan Diego", 19));
    tree.insert(Alumno("Fernando", 20));
    tree.insert(Alumno("Heider", 18));
    tree.insert(Alumno("Carlos", 23));
    tree.inorder([](const Alumno& alumno){cout << alumno << endl;});
    cout << tree.find(Alumno("Juan Diego")) << endl;

    binary_search_tree<int> tree1 {15, 10, 20, 8, 12, 18, 30, 16, 19, 21, 31};

    tree1.preorder([](auto& i){
        cout << i << " ";
    });
    cout << endl;
    tree1.remove(20);
    tree1.preorder([](auto& i){
        cout << i << " ";
    });
    cout << endl;
    tree1.postorder([](auto& i){
        cout << i << " ";
    });
    cout << endl;

    cout << tree1.min() << endl;
    cout << tree1.max() << endl;

    return 0;
}
