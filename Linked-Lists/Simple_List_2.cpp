#include <iostream>
using namespace std;

struct Node {
    int DATA;
    Node* NEXT;
    Node(int value) { DATA = value; NEXT = nullptr; }
};

class LinkedList {
    Node* START;
public:
    LinkedList() { START = nullptr; }

    void insertAtBegin(int val) {
        Node* NEW = new Node(val);
        NEW->NEXT = START;
        START = NEW;
    }

    void insertAtEnd(int val) {
        Node* NEW = new Node(val);
        if(START == nullptr) {
            START = NEW;
            return;
        }
        Node* PTR = START;
        while(PTR->NEXT != nullptr)
            PTR = PTR->NEXT;
        PTR->NEXT = NEW;
    }

    void deleteFromBegin() {
        if(START == nullptr) {
            cout << "Linked List Underflow" << endl;
            return;
        }
        Node* DEL = START;
        START = START->NEXT;
        delete DEL;
    }

    void deleteFromEnd() {
        if(START == nullptr) {
            cout << "Linked List Underflow" << endl;
            return;
        }
        if(START->NEXT == nullptr) {
            delete START;
            START = nullptr;
            return;
        }
        Node* PTR = START;
        while(PTR->NEXT->NEXT != nullptr)
            PTR = PTR->NEXT;
        delete PTR->NEXT;
        PTR->NEXT = nullptr;
    }

    void deleteFromPosition(int pos) {
        if(START == nullptr || pos <= 0) {
            cout << "Invalid Operation" << endl;
            return;
        }
        if(pos == 1) {
            deleteFromBegin();
            return;
        }
        Node* PTR = START;
        for(int i = 1; PTR != nullptr && i < pos - 1; i++)
            PTR = PTR->NEXT;
        if(PTR == nullptr || PTR->NEXT == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* DEL = PTR->NEXT;
        PTR->NEXT = PTR->NEXT->NEXT;
        delete DEL;
    }

    void traverse() {
        if(START == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* PTR = START;
        cout << "Linked List: ";
        while(PTR != nullptr) {
            cout << PTR->DATA << " -> ";
            PTR = PTR->NEXT;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList List;
    int choice, value;

    while(true) {
        cout << endl << "1: Insertion" << endl
             << "2: Deletion" << endl
             << "3: Traverse" << endl
             << "4: Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "1: Insert at Begin" << endl
                 << "2: Insert at End" << endl
                 << "Enter choice: ";
            cin >> choice;
            if(choice == 1) List.insertAtBegin(value);
            else if(choice == 2) List.insertAtEnd(value);
            else cout << "Invalid insertion choice" << endl;
        }
        else if(choice == 2) {
            cout << "1: Delete first element" << endl
                 << "2: Delete last element" << endl
                 << "3: Delete specific position" << endl
                 << "Enter choice: ";
            cin >> choice;
            if(choice == 1) List.deleteFromBegin();
            else if(choice == 2) List.deleteFromEnd();
            else if(choice == 3) {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                List.deleteFromPosition(pos);
            } else cout << "Invalid deletion choice" << endl;
        }
        else if(choice == 3) List.traverse();
        else if(choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else cout << "Invalid choice" << endl;
    }
    return 0;
}