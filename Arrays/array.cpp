#include <iostream>
using namespace std;

int MAX = 100;

void traverse (int array[], int size) {
    cout << array[0] << " ";
    for(int i=1; i < size; ) {
        cout << array[i] << " ";
        i++;
    }
}

int search(int array[], int size, int value){
    for(int i=0; i<size; i++) {
        if(array[i] == value) {
            return i;
        }
    }
    return -1;
}

void insertion(int array[], int &size, int value, int position){
    if(size >= MAX) {
        cout << "Overflow. Element cannot be inserted." << endl;
        return;
    }
    if(position < 0 || position > size) {
        cout << "Invalid Position." << endl;
        return;
    }
    if(position == size) {
        array[size] = value;
    }
    else {
        for(int i=size; i>position; i--) {
            array[i] = array[i-1];
        }
        array[position] = value;
    }
    size++;
    return;
}

int deleteByPosition(int array[], int &size, int position) {
    if(position < 0 || position >= size){
        cout << "Invalid Position" << endl;
        return -1;
    }
    int deletedValue = array[position];
    for(int i=position; i<size-1; i++) {
        array[i] = array[i+1];
    }
    cout << "Element " << deletedValue << " is deleted successfully" << endl;
    size--;
    return deletedValue;
}

void deletion (int array[], int &size, int value){
    int pos = search(array, size, value);
    if(pos == -1) {
        cout << "Element to be deleted is not found" << endl;
        return ;
    }
    int deletedValue = deleteByPosition(array, size, pos);
}

int main() {
    int array[MAX], size = 0, choice;

    giveSize : cout << "Give the size of the array: ";
    cin >> size;
    
    if(size > MAX || size < 0) {
        cout << "Invalid size !!" << endl;
        goto giveSize;
        return;
    }

    cout << "Create your array with the size you've given." << endl;
    for(int i=0; i < size; i++) {
        cout << "Enter " << i+1 << " th element: ";
        cin >> array[i];
    }

    cout << "1: Insert an element" << endl;
    cout << "2: Delete an element" << endl;
    cout << "3: Traverse the array" << endl;
    cout << "4: Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            int value, position;
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the position where you want to insert: ";
            cin >> position;
            insertion(array, size, value, position);
            break;

        case 2:
            int val;
            cout << "Enter the value to be deleted: ";
            cin >> val;
            deletion(array, size, val);
            break;
            
        case 3:
            cout << "Array elements are: ";
            traverse(array, size);
            cout << endl;
            break;

        case 4:
            cout << "Exiting the program" << endl;
            exit(0);

        default:
            cout << "Invlaid Choice. Please try again." << endl;
            break;
    }

    return 0;
}