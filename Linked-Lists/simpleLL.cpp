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
            if(START == nullptr){
                START = NEW;
                return;
            }
            Node* PTR = START;
            while(PTR->NEXT != nullptr)
                PTR = PTR->NEXT;
            PTR->NEXT = NEW;
        }

        void deleteFromBegin() {
            if(START == nullptr){
                cout << "Linked List Underflow" << endl;
                return;
            }
            Node* DEL = START;
            START = START->NEXT;
            delete DEL;
            DEL = nullptr;
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
            while(PTR->NEXT->NEXT == nullptr)
                PTR = PTR->NEXT;
            delete PTR;
            PTR = nullptr;
        }

        void deleteFromPosition(int pos) {
            if(START == nullptr || pos < 0){
                cout << "Invalid Operation. Either list is empty or position is mistyped" << endl;
                return;
            }
            if(pos == 1){
                deleteFromBegin();
                return;
            }
            Node* PTR = START;
            for(int i=1; PTR != nullptr && i < pos-1; i++)
                PTR = PTR->NEXT;
            
            if(PTR == nullptr || PTR->NEXT == nullptr){
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
            Node* PTR = START;
            cout << "Linked List : ";
            while(PTR != nullptr){
                cout << PTR->DATA << " -> ";
            }
            cout << endl;
        }
};

int main() {
    LinkedList List;

    // Pending
    return 0;
}