#include "forward/forward_list.cpp"
#include "bidirectional/bidirectional_list.cpp"
using std::cout;
using std::endl;
using std::boolalpha;

int main() {
    forward_list<int> fl ({1, 2, 3, 4}, false);
    cout << "forward list: ";
    for (const int& i: fl){
        cout << i << ' ';
    }
    cout << endl;
    cout << "bidirectional list: ";
    bidirectional_list<int> bl {1, 2, 3, 4};
    for (const int& i : bl){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
