#include "circular_array.cpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    circular_array<int> array = {1, 2, 3, 4};
    std::string step = " ";

    for_adapter(array, [&](const int& value)->void{
        cout << value << step;
    });
    cout << endl;

    array.push_back(5);
    array.push_back(6);
    array.push_front(10);
    cout << array.to_string() << endl;
    cout << array.size() << endl;
    cout << array.get_capacity() << endl;
    
    return 0;
}
