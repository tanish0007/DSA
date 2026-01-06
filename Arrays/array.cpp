#include <iostream>
using namespace std;

const int MAX = 100;  // Use const instead of variable for constant value

void traverse(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int search(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

void insertion(int array[], int &size, int value, int position) {
    if (size >= MAX) {
        cout << "Overflow. Element cannot be inserted." << endl;
        return;
    }
    if (position < 0 || position > size) {
        cout << "Invalid Position." << endl;
        return;
    }

    for (int i = size; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = value;
    size++;

    cout << "Element inserted successfully!" << endl;
}

int deleteByPosition(int array[], int &size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid Position" << endl;
        return -1;
    }
    int deletedValue = array[position];
    for (int i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    cout << "Element " << deletedValue << " is deleted successfully." << endl;
    return deletedValue;
}

void deletion(int array[], int &size, int value) {
    int pos = search(array, size, value);
    if (pos == -1) {
        cout << "Element to be deleted is not found." << endl;
        return;
    }
    deleteByPosition(array, size, pos);
}

int main() {
    int array[MAX], size = 0;

giveSize:
    cout << "Give the size of the array: ";
    cin >> size;

    if (size > MAX || size < 0) {
        cout << "Invalid size !!" << endl;
        goto giveSize;
    }

    cout << "Create your array with the size you've given." << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << "th element: ";
        cin >> array[i];
    }

    while (true) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1: Insert an element\n";
        cout << "2: Delete an element\n";
        cout << "3: Traverse the array\n";
        cout << "4: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value, position;
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position where you want to insert: ";
                cin >> position;
                insertion(array, size, value, position);
                break;
            }
            case 2: {
                int val;
                cout << "Enter the value to be deleted: ";
                cin >> val;
                deletion(array, size, val);
                break;
            }
            case 3:
                cout << "Array elements are: ";
                traverse(array, size);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid Choice. Please try again." << endl;
                break;
        }
    }
}