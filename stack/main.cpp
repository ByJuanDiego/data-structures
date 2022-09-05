#include "stack.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    stack<int> stack {1, 2, 3, 4, 5};
    while (!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }
    return  0;
}
