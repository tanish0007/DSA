// Acc to CLRS

#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX_CHAR 256

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

struct MinHeap {
    Node **A;
    int size;
};

Node* create_node(char ch, int freq, Node* left, Node* right) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->ch = ch;
    n->freq = freq;
    n->left = left;
    n->right = right;
    return n;
}

void swap(Node **a, Node **b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(MinHeap *H, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < H->size && H->A[l]->freq < H->A[smallest]->freq)
        smallest = l;
    if (r < H->size && H->A[r]->freq < H->A[smallest]->freq)
        smallest = r;
    if (smallest != i) {
        swap(&H->A[i], &H->A[smallest]);
        min_heapify(H, smallest);
    }
}

Node* extract_min(MinHeap *H) {
    Node* min = H->A[0];
    H->A[0] = H->A[H->size - 1];
    H->size--;
    min_heapify(H, 0);
    return min;
}

void insert(MinHeap *H, Node* n) {
    H->size++;
    int i = H->size - 1;
    H->A[i] = n;
    while (i != 0 && H->A[(i-1)/2]->freq > H->A[i]->freq) {
        swap(&H->A[i], &H->A[(i-1)/2]);
        i = (i-1)/2;
    }
}

void build_min_heap(MinHeap *H) {
    for (int i = H->size/2 - 1; i >= 0; --i)
        min_heapify(H, i);
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
    MinHeap H;
    H.A = (Node**)malloc(n * sizeof(Node*));
    H.size = n;
    for (int i = 0; i < n; ++i)
        H.A[i] = create_node(chars[i], freq[i], NULL, NULL);
    build_min_heap(&H);
    for (int i = 1; i < n; ++i) {
        Node *x = extract_min(&H);
        Node *y = extract_min(&H);
        Node *z = create_node(0, x->freq + y->freq, x, y);
        insert(&H, z);
    }
    int code[MAX_CHAR], depth = 0;
    get_codes(H.A[0], code, depth);
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