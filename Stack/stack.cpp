#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

const int MAX = 100;
int TOP = -1;

bool isNumber(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int getChoice() {
    string input;
    cout << "Enter choice: ";
    cin >> input;

    while (!isNumber(input)) {
        cout << "Invalid input! Please enter a number: ";
        cin >> input;
    }
    return stoi(input);
}

void push(int stack[], int &top, int value) {
    if(top == MAX-1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack[++top] = value;
    cout << value << " is inserted successfully" << endl;
}

int pop(int stack[], int &top) {
    if(top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int del = stack[top--];
    cout << "Element " << del << " is deleted successfully" << endl;
    return del;
}

void traverse(int stack[], int top) {
    if(top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    for(int i=top; i>=0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[MAX], choice;

    while(true) {
        cout << endl 
             << "1: Push an element" << endl 
             << "2: Pop an element" << endl 
             << "3: Traverse the stack" << endl 
             << "4: Exit" << endl;

        choice = getChoice();

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter the value to push: ";
            cin >> value;
            push(array, TOP, value);
            break;
        }
        case 2: {
            int popped = pop(array, TOP);
            if(popped != -1) {
                cout << "Popped value: " << popped << endl;
            }
            break;
        }
        case 3:
            traverse(array, TOP);
            break;

        case 4:
            cout << "Exiting.." << endl;
            exit(0);

        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
