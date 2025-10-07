#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX_CHAR 256

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

struct ListNode {
    Node *tree;
    ListNode *next;
};

ListNode* create_list_node(Node *tree) {
    ListNode *ln = (ListNode*)malloc(sizeof(ListNode));
    ln->tree = tree;
    ln->next = NULL;
    return ln;
}

void insert_sorted(ListNode **head, Node *tree) {
    ListNode *new_node = create_list_node(tree);
    if (*head == NULL || tree->freq < (*head)->tree->freq) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    ListNode *curr = *head;
    while (curr->next != NULL && curr->next->tree->freq <= tree->freq) {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

Node* extract_min(ListNode **head) {
    if (*head == NULL) return NULL;
    ListNode *min_node = *head;
    *head = (*head)->next;
    Node *min_tree = min_node->tree;
    free(min_node);
    return min_tree;
}

void get_codes(Node *root, int code[], int depth) {
    if (root->left) {
        code[depth] = 0;
        get_codes(root->left, code, depth+1);
    }
    if (root->right) {
        code[depth] = 1;
        get_codes(root->right, code, depth+1);
    }
    if (!root->left && !root->right) {
        std::cout << root->ch << ": ";
        for (int i = 0; i < depth; ++i)
            std::cout << code[i];
        std::cout << "\n";
    }
}

void count_freq(const char str[], char chars[], int freq[], int &n) {
    int temp[MAX_CHAR] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        temp[(unsigned char)str[i]]++;
    n = 0;
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (temp[i] > 0) {
            chars[n] = (char)i;
            freq[n] = temp[i];
            n++;
        }
    }
}

void huffman(char chars[], int freq[], int n) {
    ListNode *pq = NULL;
    for (int i = 0; i < n; ++i) {
        Node *leaf = (Node*)malloc(sizeof(Node));
        leaf->ch = chars[i];
        leaf->freq = freq[i];
        leaf->left = NULL;
        leaf->right = NULL;
        insert_sorted(&pq, leaf);
    }
    for (int i = 1; i < n; ++i) {
        Node *x = extract_min(&pq);
        Node *y = extract_min(&pq);
        Node *z = (Node*)malloc(sizeof(Node));
        z->ch = 0;
        z->freq = x->freq + y->freq;
        z->left = x;
        z->right = y;
        insert_sorted(&pq, z);
    }
    int code[MAX_CHAR], depth = 0;
    get_codes(pq->tree, code, depth);
}

int main() {
    char str[100];
    std::cout << "Enter string: ";
    std::cin.getline(str, 100);
    char chars[MAX_CHAR];
    int freq[MAX_CHAR], n;
    count_freq(str, chars, freq, n);
    huffman(chars, freq, n);
    return 0;
}