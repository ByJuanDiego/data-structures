#include "circular_array.cpp"
#include <iostream>
using std::cout;
using std::endl;

template<typename T, typename Function>
void for_adapter(circular_array<T>& array, const Function& function) {
    for (int i=0; i<array.size(); i++){
        function(array[i]);
    }
}

template<typename T, typename Function>
void for_adapter_ptr(circular_array<T>& array, const Function& function){
    for (const T& value: array){
        function(value);
    }
}

int main() {
    std::string step = " ";
    circular_array<int> array;
    array.push_front(1);
    array.push_back(7);
    array.push_front(3);
    array.push_back(4);
    array.pop_back();
    array.pop_front();

    for (const int & i : array){
        cout << i << step;
    }

    return 0;
}
