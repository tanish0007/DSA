// Tree implementation using Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* LEFT;
    Node* RIGHT;

    Node(int value) { data = value; LEFT = nullptr; RIGHT = nullptr; }
};

Node* insert(Node* ROOT, int value) {
    if(ROOT == nullptr) return new Node(value);
    if(value < ROOT->data) ROOT->LEFT = insert(ROOT->LEFT, value);
    else if(value > ROOT->data) ROOT->RIGHT = insert(ROOT->RIGHT, value);

    return ROOT;
}

bool search(Node* ROOT, int value){
    if(ROOT == nullptr || ROOT->data == value ) return false;
    if(ROOT->data == value) return true;
    if(value < ROOT->data) return search(ROOT->LEFT, value);
    else if(value > ROOT->data) return search(ROOT->RIGHT, value);
}

void inorder(Node* ROOT) {
    if(ROOT == nullptr) return;
    inorder(ROOT->LEFT);
    cout << ROOT->data << " ";
    inorder(ROOT->RIGHT);
}

void preorder(Node* ROOT) {
    if(ROOT == nullptr) return;
    cout << ROOT->data << " ";
    preorder(ROOT->LEFT);
    preorder(ROOT->RIGHT);
}

void postorder(Node* ROOT) {
    if(ROOT == nullptr) return;
    postorder(ROOT->LEFT);
    postorder(ROOT->RIGHT);
    cout << ROOT->data << " ";
}

int main() {
    int choice;
    int value;
    Node* root = nullptr;

    start:cout << "1: Insert a node" << endl;
    cout << "2: Search for a node" << endl;
    cout << "3: Traversal" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter the node you want to insert: ";
            cin >> value;
            insert(root, value);
            cout << "Node inserted successfully";
            break;

        case 2: 
            cout << "Search for a node: ";
            cin >> value;
            bool found;
            found = search(root, value);
            if(found) cout << "Element is found";
            else cout << "Element is not found";
            break;

        case 3:
            int ch;
            cout << "1: Inorder" << endl;
            cout << "2: Preorder" << endl;
            cout << "3: Postorder" << endl;
            cin >> ch;
            switch (ch) {
                case 1:
                    inorder(root);
                    break;
                
                case 2:
                    preorder(root);
                    break;

                case 3:
                    postorder(root);
                    break;
                
                default:
                    break;
                }
            break;

        default:
            break;
    }
    goto start;

        return 0;
}