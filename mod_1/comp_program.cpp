#include <iostream>

#define DEBUG 1

using namespace std;

int  getValue(string label);
void sum(int& a, int& b);
void subtract(int& a, int& b);
void mult(int& a, int& b);
void divide(int& a, int& b);

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

    cout << "What operations you need?\n";

    cout << "1: sum\n";
    cout << "2: subtract\n";
    cout << "3: multiply\n";
    cout << "4: divide\n";
    cout << "> ";

    int operandus;
    cin >> operandus;

    switch (operandus) {
        case 1:
            int a = getValue("add");
            sum(a, myVector[op]);
            break;
        case 2:
            int b = getValue("subtract");
            subtract(myVector[op], b);
            break;
        case 3:
            int a = getValue("multiply");
            mult(a, myVector[op]);
            break;
        case 4:
            int b = getValue("divide");
            divide(myVector[op], b);
            break;
        default:
            return 1;
            break;
    }

    return 0;
}

int getValue(string label) {
    int input;

    cout << "Value to " << label << ": ";
    cin >> input;

    return input;
}

void sum(int &a, int &b) {

    #ifdef DEBUG

    #endif

    a += b;
}

void subtract(int &a, int &b) {

    #ifdef DEBUG

    #endif

    a -= b;
}

void mult(int &a, int &b) {

    #ifdef DEBUG

    #endif

    a *= b;
}

void divide(int &a, int &b) {

    #ifdef DEBUG

    #endif
    if(b != 0) {
        a /= b;
    }
}