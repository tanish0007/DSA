#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> v = {10, 20, 30};
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.push_back(90);

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.pop_back();
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    v.clear();
    cout << "hehe" << v.size() << v.capacity() << endl;

    return 0;
}