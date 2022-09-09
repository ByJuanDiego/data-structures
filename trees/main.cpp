#include <iostream>
#include "BSTree/binary_search_tree.h"
using std::cout;
using std::endl;

int main() {
    binary_search_tree<int> arbolito {18, 25, 12, 16, 5, 7};
    arbolito.inorder([](const int& i){cout << i << endl;});
    return 0;
}
