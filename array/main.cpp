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

    for (circular_array<int>::iterator it = array.begin(); it != array.end(); ++it){
        cout << *it << step;
    }
    cout << endl;

    for (const auto & i : array){
        cout << i << step;
    }
    cout << endl;

    for_adapter(array, [&](const int& value)->void {
        cout << value << step;
    });
    cout << endl;

    for_adapter_ptr(array, [&](const int& value)->void {
        cout << value << step;
    });
    cout << endl;

    cout << array.to_string(step) << endl;
    return 0;
}
