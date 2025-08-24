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
            while(PTR->NEXT->NEXT != nullptr)
                PTR = PTR->NEXT;
            delete PTR->NEXT;
            PTR->NEXT = nullptr;
        }

        void deleteFromPosition(int pos) {
            if(START == nullptr || pos <= 0){
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
        cout << endl << "1: Insertion in List" << endl << "2: Deletion in List" << endl << "3: Traverse the List" << endl << "4: EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Insert : cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Where do you want to insert " << value << " ?" << endl;
                cout << "1: Insert at Begin" << endl << "2: Insert at End" << endl << "3: Insert after a specific element" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                switch(choice) {
                    case 1:
                        List.insertAtBegin(value);
                        cout << value << " inserted in beginning successfully" << endl;
                        break;

                    case 2:
                        List.insertAtEnd(value);
                        cout << value << " inserted in end successfully" << endl;
                        break;

                    default:
                        cout << "Invalid insertion choice" << endl;
                        goto Insert; 
                        break;                       
                }
                break;

            case 2:
                Delete : cout << "From where you want to delete ?";
                cout << "1: Delete first element" << endl << "2: Delete last element" << endl << "3: Delete specific element" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                
                switch (choice) {
                    case 1:
                        List.deleteFromBegin();
                        break;

                    case 2:
                        List.deleteFromEnd();
                        break;

                    case 3:
                        int pos;
                        cout << "Enter the position of specific element";
                        cin >> pos;
                        List.deleteFromPosition(pos);
                        break;

                    default:
                        cout << "Invalid deletion choice" << endl;
                        goto Delete;
                        break;
                }
                break;

            case 3:
                List.traverse();
                break;

            case 4:
                cout << "Exiting..." << endl;
                exit(0);
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}