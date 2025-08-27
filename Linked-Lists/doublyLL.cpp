#include <iostream>
using namespace std;

struct Node {
    Node* FORWARD;
    int DATA;
    Node* BACKWARD;

    Node(int value) { DATA = value; FORWARD = nullptr; BACKWARD = nullptr; }
};

class LinkedList {
    Node* START;
    Node* END;

    public:
        LinkedList() { 
            START = nullptr; 
            END = nullptr; 
        }

        void insertAtBegin(int val) {
            Node* NEW = new Node(val);
            if(START == nullptr) {
                START = NEW;
                END = NEW;
                return;
            }
            NEW->FORWARD = START;
            NEW->BACKWARD = nullptr;
            START->BACKWARD = NEW;
            START = NEW;
        }

        void insertAtEnd(int val) {
            if(END == nullptr) {
                insertAtBegin(val);
                return;
            }
            Node* NEW = new Node(val);
            NEW->FORWARD = nullptr;
            NEW->BACKWARD = END;
            END->FORWARD = NEW;
            END = NEW;
        }

        void deleteFirst() {
            if(START == nullptr) {
                cout << "Linked List Underflow" << endl;
                return;
            }
            Node* DEL = START;
            START = START->FORWARD;
            if(START != nullptr) START->BACKWARD = nullptr;
            else END = nullptr;
            delete DEL;
            DEL = nullptr;
        }

        void deleteLast() {
            if(END == nullptr) {
                cout << "Linked List Underflow" << endl;
                return;
            }
            Node* DEL = END;
            END = END->BACKWARD;
            if(END != nullptr) END->FORWARD = nullptr;
            else START = nullptr;
            delete DEL;
            DEL = nullptr;
        }

        void deleteUsingPosFromStart(int pos) {
            if(START == nullptr || pos <= 0) {
                cout << "Invalid Operation. Either list is empty or position is mistyped" << endl;
                return;
            }
            if(pos == 1) {
                deleteFirst();
                return;
            }
            Node* PTR = START;
            for(int i=1; PTR != nullptr && i < pos-1; i++)
                PTR = PTR->FORWARD;
            if(PTR == nullptr || PTR->FORWARD == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            Node* DEL = PTR->FORWARD;
            PTR->FORWARD = DEL->FORWARD;
            if(DEL->FORWARD != nullptr) DEL->FORWARD->BACKWARD = PTR;
            delete DEL;
            DEL = nullptr;
        }

        void deleteUsingPosFromEnd(int pos) {
            if(END == nullptr || pos <= 0) {
                cout << "Invalid Operation. Either list is empty or position is mistyped" << endl;
                return;
            }
            if(pos == 1) {
                deleteLast();
                return;
            }
            Node* PTR = END;
            for(int i=1; PTR != nullptr && i < pos-1; i++)
                PTR = PTR->BACKWARD;
            if(PTR == nullptr || PTR->BACKWARD == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            Node* DEL = PTR->BACKWARD;
            PTR->BACKWARD = DEL->BACKWARD;
            if(DEL->BACKWARD != nullptr) DEL->BACKWARD->FORWARD = PTR;
            delete DEL;
            DEL = nullptr;
        }

        void traverse() {
            if(START == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            Node* PTR = START;
            cout << "Linked List: ";
            while(PTR != nullptr) {
                cout << PTR->DATA << " <-> ";
                PTR = PTR->FORWARD;
            }
            cout << "NULL" << endl;
        }

        void traverseReverse() {
            if(END == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            Node* PTR = END;
            cout << "Linked List in Reverse: ";
            while(PTR != nullptr) {
                cout << PTR->DATA << " <-> ";
                PTR = PTR->BACKWARD;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList Doubly;
    int choice, value, pos;

    while (true) {
        cout << endl;
        cout << "1: Insertion in List" << endl;
        cout << "2: Deletion in List" << endl;
        cout << "3: Traverse Forward" << endl;
        cout << "4: Traverse Reverse" << endl;
        cout << "5: EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // ----------------- INSERTION -----------------
            case 1:
            Insert:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Where do you want to insert " << value << " ?" << endl;
                cout << "1: Insert at Begin" << endl;
                cout << "2: Insert at End" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        Doubly.insertAtBegin(value);
                        cout << value << " inserted at beginning successfully" << endl;
                        break;

                    case 2:
                        Doubly.insertAtEnd(value);
                        cout << value << " inserted at end successfully" << endl;
                        break;

                    default:
                        cout << "Invalid insertion choice!" << endl;
                        goto Insert;
                }
                break;

            // ----------------- DELETION -----------------
            case 2:
            Delete:
                cout << "From where do you want to delete?" << endl;
                cout << "1: Delete first element" << endl;
                cout << "2: Delete last element" << endl;
                cout << "3: Delete by position from START" << endl;
                cout << "4: Delete by position from END" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        Doubly.deleteFirst();
                        break;

                    case 2:
                        Doubly.deleteLast();
                        break;

                    case 3:
                        cout << "Enter the position (from START): ";
                        cin >> pos;
                        Doubly.deleteUsingPosFromStart(pos);
                        break;

                    case 4:
                        cout << "Enter the position (from END): ";
                        cin >> pos;
                        Doubly.deleteUsingPosFromEnd(pos);
                        break;

                    default:
                        cout << "Invalid deletion choice!" << endl;
                        goto Delete;
                }
                break;

            // ----------------- TRAVERSE -----------------
            case 3:
                Doubly.traverse();
                break;

            case 4:
                Doubly.traverseReverse();
                break;

            // ----------------- EXIT -----------------
            case 5:
                cout << "Exiting..." << endl;
                exit(0);

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}