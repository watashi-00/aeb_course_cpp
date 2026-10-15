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

    if(!op) {
        return 1;
    }
    
    if(op >= size || size < 0) {
        return 1;
    }

    

    return 0;
}


void sum(int &a, int &b) {
    a += b;
}

void subtract(int &a, int &b) {
    a -= b;
}

void mult(int &a, int &b) {
    a *= b;
}

void div(int &a, int &b) {
    if(b != 0) {
        a /= b;
    }
}