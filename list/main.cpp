#include <iostream>
#include <functional>
#include "forward/forward_list.h"
#include "bidirectional/bidirectional_list.h"
using std::cout;
using std::endl;
using std::boolalpha;

void test1(){
    cout << __PRETTY_FUNCTION__ << endl;

    bidirectional_list<int> bl {10};
    bl.sorted_insert(6);
    for (int i: bl){
        cout << i << " ";
    }
    cout << endl;

    bidirectional_list<int> bl2 {1, 3, 4, 20};
    for (int i: bl2){
        cout << i << " ";
    }
    cout << endl;

    bidirectional_list<int> bl3 = bl.sorted_join(bl2);
    for (int i: bl3){
        cout << i << " ";
    }
    cout << endl;

    bidirectional_list<int> bl4 {1, 2, 3, 2, 1};
    cout << boolalpha << bl4.is_palindrome() << endl;

    bidirectional_list<int> bl5 {1, 2, 6, 4, 5, 3 ,5, 7, 0};
    bl5.reverse();
    for (int i: bl5){
        cout << i << " ";
    }
    cout << endl;
    bl5.insert(10, static_cast<index_t>(bl5.size()));
    bl5.insert(10, 0);
    for (int i: bl5){
        cout << i << " ";
    }
    cout << endl;
    cout << bl5.size() << endl;
}

void test2(){
    cout << __PRETTY_FUNCTION__ << endl;

    forward_list<int> fl {1, 3, 2};
    cout << fl << endl;
    fl.remove_once_if([](int i){return i==1;});
    cout << fl << endl;
}

void test3(){
    cout << __PRETTY_FUNCTION__ << endl;

    std::function<bool(int)> lambda = [](const int& i)->bool {
        return i==1;
    };
    forward_list<int> fl {2, 1, 2, 1, 4, 1, 2,  3, 4, 5};
    cout << fl << endl;
    while (fl.find_if(lambda)){
        fl.remove_once_if(lambda);
    }
    cout << fl << endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
