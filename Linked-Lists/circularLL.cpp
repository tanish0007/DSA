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
            if(START == nullptr){
                NEW->NEXT = NEW;
                START = NEW;
                return;
            }
            Node* PTR = START;
            while(PTR->NEXT != START){
                PTR = PTR->NEXT;
            }
            NEW->NEXT = START;
            PTR->NEXT = NEW;
            START = NEW;
        }

        void insertAtEnd(int val) {
            Node* NEW = new Node(val);
            if(START == nullptr){
                insertAtBegin(val);
                return;
            }
            Node* PTR = START;
            while(PTR->NEXT != START){
                PTR = PTR->NEXT;
            }
            PTR->NEXT = NEW;
            NEW->NEXT = START;
        }

        void deleteFirst() {
            if(START == nullptr){
                cout << "Linked List Underflow" << endl;
                return;
            }
            if(START->NEXT == START){
                delete START;
                START = nullptr;
                return;
            }
            Node* DEL = START;
            Node* PTR = START;

            while(PTR->NEXT != START)
                PTR = PTR->NEXT;
            
            PTR->NEXT = START->NEXT;
            START = START->NEXT;
            delete DEL;
            DEL = nullptr;
        }

        void deleteLast() {
            if(START == nullptr) {
                cout << "Linked List Underflow" << endl;
                return;
            }
            if(START->NEXT == START) {
                delete START;
                START = nullptr;
                return;
            }
            Node* PTR = START;
            while(PTR->NEXT->NEXT != START)
                PTR = PTR->NEXT;

            Node* DEL = PTR->NEXT;
            PTR->NEXT= START; 
            
            delete DEL;
            DEL = nullptr;
        }

        void deleteFromPosition(int pos) {
            if(START == nullptr || pos <= 0){
                cout << "Invalid Operation. Either list is empty or position is mistyped" << endl;
                return;
            }
            if(pos == 1){
                deleteFirst();
                return;
            }
            Node* PTR = START;
            for(int i=1; PTR->NEXT != START && i < pos-1; i++)
                PTR = PTR->NEXT;
            
            if(PTR->NEXT == START){
                cout << "Position is out of range!!" << endl;
                return;
            }
            Node* DEL = PTR->NEXT;
            PTR->NEXT = PTR->NEXT->NEXT;
            delete DEL;
            DEL = nullptr;
            
        }

        void traverse() {
            if(START == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            
        }
};

int main() {
    LinkedList List;
    int choice, value;

    while(true) {
        cout << endl << "1: Insertion in List" << endl << "2: Deletion in List" << endl << "3: Traverse the List" << endl << "4: EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

    }

    return 0;
}