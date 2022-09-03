#include "forward/forward_list.cpp"
using std::cout;
using std::endl;

int main() {
    forward_list<int> fl {1, 2, 3, 4};
    cout << fl << endl;
    fl.push_front(4);
    fl.push_back(10);
    while (!fl.empty()){
        fl.pop_back();
    }
    fl.push_back(4);
    fl.push_front(1);
    cout << std::boolalpha << fl.sorted() << endl;
    return 0;
}
