#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int ipAdd;
    int dataPacket;
    Node *left;
    Node *right;
    Node *parent;
};

struct SplayTree {
    Node *root;
};

Node *newNode(int ipAdd) {
    Node *n = new Node();
    n->ipAdd = ipAdd;
    n->dataPacket = 0;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    return n;
}

SplayTree *newSplayTree() {
    SplayTree *t = new SplayTree();
    t->root = nullptr;
    return t;
}

Node *maximum(SplayTree *t, Node *x) {
    while (x->right != nullptr)
        x = x->right;
    return x;
}

void leftRotate(SplayTree *t, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        t->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(SplayTree *t, Node *x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        t->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void splay(SplayTree *t, Node *n) {
    while (n->parent != nullptr) {
        if (n->parent == t->root) {
            if (n == n->parent->left) {
                rightRotate(t, n->parent);
            } else {
                leftRotate(t, n->parent);
            }
        } else {
            Node *p = n->parent;
            Node *g = p->parent;
            if (n->parent->left == n && p->parent->left == p) {
                rightRotate(t, g);
                rightRotate(t, p);
            } else if (n->parent->right == n && p->parent->right == p) {
                leftRotate(t, g);
                leftRotate(t, p);
            } else if (n->parent->right == n && p->parent->left == p) {
                leftRotate(t, p);
                rightRotate(t, g);
            } else if (n->parent->left == n && p->parent->right == p) {
                rightRotate(t, p);
                leftRotate(t, g);
            }
        }
    }
}

void insert(SplayTree *t, Node *n) {
    Node *y = nullptr;
    Node *temp = t->root;
    while (temp != nullptr) {
        y = temp;
        if (n->ipAdd < temp->ipAdd) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    n->parent = y;
    if (y == nullptr) {
        t->root = n;
    } else if (n->ipAdd < y->ipAdd) {
        y->left = n;
    } else {
        y->right = n;
    }
    splay(t, n);
}

Node *search(SplayTree *t, Node *n, int x) {
    if (n == nullptr) return nullptr;
    if (x == n->ipAdd) {
        splay(t, n);
        return n;
    } else if (x < n->ipAdd) {
        return search(t, n->left, x);
    } else {
        return search(t, n->right, x);
    }
}

void inorder(SplayTree *t, Node *n, const string &cmn) {
    if (n != nullptr) {
        inorder(t, n->left, cmn);
        cout << cmn << n->ipAdd << " -> " << n->dataPacket << endl;
        inorder(t, n->right, cmn);
    }
}

int main() {
    string cmn = "192.168.3.";
    SplayTree *t = newSplayTree();
    Node *nodes[11];
    int ipAddresses[11] = {104, 112, 117, 124, 121, 108, 109, 111, 122, 125, 129};
    
    for (int i = 0; i < 11; ++i) {
        nodes[i] = newNode(ipAddresses[i]);
        insert(t, nodes[i]);
    }

    srand(time(0));
    for (int i = 0; i < 11; ++i) {
        int data = rand() % 200;
        Node *temp = search(t, t->root, ipAddresses[i]);
        if (temp != nullptr) {
            temp->dataPacket = data;
        }
    }

    cout << "IP ADDRESS -> DATA PACKET\n";
    inorder(t, t->root, cmn);
    return 0;
}
