#include <iostream>
using namespace std;

const int MAX = 4;
int FRONT = -1;
int REAR = -1;

void enqueue(int queue[], int &front, int &rear, int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    cout << value << " inserted successfully" << endl;
}

int dequeue(int queue[], int &front, int &rear) {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    int del = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    cout << del << " element is deleted" << endl;
    return del;
}

void traverse(int queue[], int &front, int &rear) {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    if (front > rear) {
        for (int i = front; i < MAX; i++) cout << queue[i] << " ";
        for (int i = 0; i <= rear; i++) cout << queue[i] << " ";
    } else {
        for (int i = front; i <= rear; i++) cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int QUEUE[MAX], choice;
    while (true) {
        cout << endl;
        cout << "1: Insert an element" << endl;
        cout << "2: Delete an element" << endl;
        cout << "3: Traverse the Queue" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                enqueue(QUEUE, FRONT, REAR, value);
                break;
            }
            case 2:
                dequeue(QUEUE, FRONT, REAR);
                break;
            case 3:
                traverse(QUEUE, FRONT, REAR);
                break;
            case 4:
                cout << "Exiting.." << endl;
                return 0;
            default:
                cout << "Invalid Choice" << endl;
        }
    }
}
