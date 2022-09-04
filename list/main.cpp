#include "forward/forward_list.cpp"
#include <forward_list>
using std::cout;
using std::endl;
using std::boolalpha;

int main() {
    forward_list<int> fl ({1, 2, 3, 6}, false);
    fl.push_front(9);
    fl.push_back(10);
    fl.push_back(4);
    fl.push_front(0);

    cout << "before sort: " << fl << endl;
    fl.sort();
    cout << "after sort: " << fl << endl;
    cout << "fl[3] = " << fl[3] << endl;
    fl[3] *= 7;
    cout << fl << endl;

    int a = fl.front();
    int b = fl.back();
    cout << "front: " << a << " back: " << b << endl;

    fl.pop_back();
    fl.pop_front();

    for (const int& i : fl){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
