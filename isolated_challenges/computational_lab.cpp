#include <iostream>
#include <limits>

#define DEBUG 1

using namespace std;

int getValue(string label);
void sum(int &value);
void subtract(int &value);
void mult(int &value);
void divide(int &value);
void debugPrint(const string &operation, int &a, int &b);


typedef struct vector_data_t {
    size_t  length;
    size_t  element_size;
    void    *vector;
} VectorData;

typedef struct user_data_t {
    VectorData *vector;
    string  username;
} UserData;

int welcome_menu(UserData& user);
int menu_0(UserData& user);
int menu_1(UserData& user);


int main() {
    constexpr int size = 8;
    int myVector[size] = {};

    string username;
    
    cout<< "Write your name: ";
    cin >> username;

    VectorData vectorData {
        .length = size,
        .element_size = sizeof(int),
        .vector = myVector
    };

    UserData userData {
        .vector = &vectorData,
        .username = username
    };


    bool running = true;

    while (running) {
        menu_1(userData);
    }

    return 0;
}

int getValue(string label) {
    int input;

    cout << "Value to " << label << ": ";
    cin >> input;

    return input;
}

void debugPrint(const string &operation, int &a, int &b) {
    cout << "[DEBUG] Operation: " << operation << '\n';
    cout << "[DEBUG] Operand A: " << a << '\n';
    cout << "[DEBUG] Operand B: " << b << '\n';
    cout << "[DEBUG] --------------------\n";
}

void sum(int &value) {
    int operand = getValue("add");

#if DEBUG
    debugPrint("sum", value, operand);
#endif

    value += operand;
    cout << "Result: " << value << '\n';
}

void subtract(int &value) {
    int operand = getValue("subtract");

#if DEBUG
    debugPrint("subtract", value, operand);
#endif

    value -= operand;
    cout << "Result: " << value << '\n';
}

void mult(int &value) {
    int operand = getValue("multiply");

#if DEBUG
    debugPrint("multiply", value, operand);
#endif

    value *= operand;
    cout << "Result: " << value << '\n';
}

void divide(int &value) {
    int operand = getValue("divide");

#if DEBUG
    debugPrint("divide", value, operand);
#endif

    if (operand != 0) {
        value /= operand;
        cout << "Result: " << value << '\n';
    } else {
        cout << "Error: division by zero.\n";
    }
}

int menu_1(UserData& user) {
    auto* myVector = static_cast<int*>(user.vector->vector);
    const size_t size = user.vector->length;

    for (int i = 0; i < size; i++) {
            cout << "OP " + to_string(i) + ":\t";
            cout << "[ " + to_string(myVector[i]) + " ]\n";
        }

        int op;
        cout << "Choose one option to change: ";
        cin >> op;

        if (op < 0 || op >= size) {
            return 1;
        }

        cout << "What operations you need?\n";
        cout << "0: exit\n";
        cout << "1: sum\n";
        cout << "2: subtract\n";
        cout << "3: multiply\n";
        cout << "4: divide\n";
        cout << "> ";

        int operandus;
        cin >> operandus;

        switch (operandus) {
            case 0:
                return 0xFF;
                break;
            case 1:
                sum(myVector[op]);
                break;
            case 2:
                subtract(myVector[op]);
                break;
            case 3:
                mult(myVector[op]);
                break;
            case 4:
                divide(myVector[op]);
                break;
            default:
                break;
        }
        return 0x00;
}

int welcome_menu(UserData& user) {
    cout << "================================\n";
    cout << "       Welcome, " << user.username << "!\n";
    cout << "================================\n\n";

    menu_0(user);

    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}

int menu_0(UserData& user) {
    cout << "User Information\n";
    cout << "--------------------\n";
    cout << "Username: " << user.username << '\n';
    cout << "Vector length: " << user.vector->length << '\n';
    cout << "Element size: " << user.vector->element_size << " bytes\n";
    cout << "Vector address: " << user.vector->vector << '\n';
    cout << "--------------------\n";

    return 0;
}