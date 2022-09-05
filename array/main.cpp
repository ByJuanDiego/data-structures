#include "circular_array.h"
#include <iostream>
using std::cout;
using std::endl;

template<typename T, typename Function>
void for_adapter(circular_array<T>& array, const Function& function){
    for (const T& value: array){
        function(value);
    }
}

int main() {
    circular_array<int> array;
    array.push_front(1);
    array.push_back(7);
    array.push_front(3);
    array.push_back(4);
    array.pop_back();
    array.pop_front();

    for_adapter(array, [](const int& value)->void {
        cout << value << " ";
    });
    cout << endl;

    return 0;
}
