#include <iostream>

using namespace std;

int main (){

    constexpr int size = 8;
    int myVector[size] = {};

    for(int i = 0; i < size; i++) {
        cout << "OP " + to_string(i) + ":\t";
        cout << "[ " + to_string(myVector[i]) + " ]\n";
    }
    int op;
    cout << "Choose one option to change: ";
    cin >> op;

    

    return 0;
}