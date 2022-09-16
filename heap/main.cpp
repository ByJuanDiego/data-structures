#include <iostream>
#include "heap.h"
using std::cout;
using std::endl;

void test2(){
    heap<int> heap(5); //tamaño inicial del vector es 5
    heap.push(4);
    heap.push(1);
    heap.push(3);
    heap.push(2);
    heap.push(16);
    heap.push(9);
    heap.push(10);
    heap.push(14);
    heap.push(8);
    heap.push(7);
    heap.display(cout);//16,14,10,8,7,3,9,1,4,2
    cout << endl;
    heap.pop();
    heap.pop();
    heap.display(cout);//10,8,9,4,7,3,2,1
    cout << endl;
    cout << heap.max() << endl;
}

void test1(){
    vector<int> elements = {4,1,3,2,16,9,10,14,8,7};
    heap<int>::build_from(elements);
    for(auto& a : elements){
        cout << a << ",";//16,14,10,8,7,9,3,2,4,1,
    }
    cout<<endl;
}

int main(){
    test1();
    test2();
    return 0;
}
