#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = nullptr; }
};

class BinaryTree {
    Node* root;

    void insert(Node*& node, int val) {
        if(!node) node = new Node(val);
        else if(val < node->data) insert(node->left, val);
        else insert(node->right, val);
    }

    void inorder(Node* node) {
        if(!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if(!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if(!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() { root = nullptr; }

    void insert(int val) { insert(root, val); }
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while(true) {
        cout << endl << "1: Insert" << endl
             << "2: Inorder Traversal" << endl
             << "3: Preorder Traversal" << endl
             << "4: Postorder Traversal" << endl
             << "5: Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
        }
        else if(choice == 2) tree.inorder();
        else if(choice == 3) tree.preorder();
        else if(choice == 4) tree.postorder();
        else if(choice == 5) {
            cout << "Exiting..." << endl;
            break;
        }
        else cout << "Invalid choice" << endl;
    }
    return 0;
}
