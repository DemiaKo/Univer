#pragma once
#include <iostream>
#include <stdexcept>

struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode*) const;
    int balanceFactor(AVLNode*) const;
    void fixHeight(AVLNode*);

    AVLNode* rotateRight(AVLNode*);
    AVLNode* rotateLeft(AVLNode*);
    AVLNode* balance(AVLNode*);

    AVLNode* insert(AVLNode*, int);
    AVLNode* findMin(AVLNode*) const;
    AVLNode* removeMin(AVLNode*);
    AVLNode* remove(AVLNode*, int);
    bool contains(AVLNode*, int) const;

    void destroyTree(AVLNode*);
    AVLNode* copyTree(AVLNode*);

    void printTree(AVLNode*, int, std::ostream&) const;

public:
    AVLTree();
    ~AVLTree();
    AVLTree(const AVLTree&);
    AVLTree& operator=(const AVLTree&);

    void insert(int);
    void remove(int);
    bool contains(int) const;
    void print(std::ostream&) const;

    int getRootKey() const;
    int getRootHeight() const;
    bool isEmpty() const;
};