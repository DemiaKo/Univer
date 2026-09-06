#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(AVLNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

AVLNode* AVLTree::copyTree(AVLNode* node) {
    if (!node) return nullptr;
    AVLNode* newNode = new AVLNode(node->key);
    newNode->height = node->height;
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    return newNode;
}

AVLTree::AVLTree(const AVLTree& other) {
    root = copyTree(other.root);
}

AVLTree& AVLTree::operator=(const AVLTree& other) {
    if (this != &other) {
        destroyTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

int AVLTree::height(AVLNode* node) const {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(AVLNode* node) const {
    return node ? height(node->right) - height(node->left) : 0;
}

void AVLTree::fixHeight(AVLNode* node) {
    if (node) {
        int hl = height(node->left);
        int hr = height(node->right);
        node->height = (hl > hr ? hl : hr) + 1;
    }
}

AVLNode* AVLTree::rotateRight(AVLNode* p) {
    AVLNode* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

AVLNode* AVLTree::rotateLeft(AVLNode* q) {
    AVLNode* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

AVLNode* AVLTree::balance(AVLNode* p) {
    if (!p) return nullptr;
    fixHeight(p);

    if (balanceFactor(p) == 2) {
        if (balanceFactor(p->right) < 0) {
            p->right = rotateRight(p->right);
        }
        return rotateLeft(p);
    }
    if (balanceFactor(p) == -2) {
        if (balanceFactor(p->left) > 0) {
            p->left = rotateLeft(p->left);
        }
        return rotateRight(p);
    }
    return p;
}

AVLNode* AVLTree::insert(AVLNode* p, int k) {
    if (!p) return new AVLNode(k);
    if (k < p->key) {
        p->left = insert(p->left, k);
    }
    else if (k > p->key) {
        p->right = insert(p->right, k);
    }
    else {
        throw std::invalid_argument("Дублікати у множині/дереві не підтримуються!");
    }
    return balance(p);
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

AVLNode* AVLTree::findMin(AVLNode* p) const {
    return p->left ? findMin(p->left) : p;
}

AVLNode* AVLTree::removeMin(AVLNode* p) {
    if (!p->left) return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

AVLNode* AVLTree::remove(AVLNode* p, int k) {
    if (!p) throw std::invalid_argument("Елемент не знайдено!");

    if (k < p->key) {
        p->left = remove(p->left, k);
    }
    else if (k > p->key) {
        p->right = remove(p->right, k);
    }
    else {
        AVLNode* l = p->left;
        AVLNode* r = p->right;
        delete p;
        if (!r) return l;

        AVLNode* minNode = findMin(r);
        minNode->right = removeMin(r);
        minNode->left = l;
        return balance(minNode);
    }
    return balance(p);
}

void AVLTree::remove(int key) {
    root = remove(root, key);
}

bool AVLTree::contains(AVLNode* p, int k) const {
    if (!p) return false;
    if (k == p->key) return true;
    if (k < p->key) return contains(p->left, k);
    return contains(p->right, k);
}

bool AVLTree::contains(int key) const {
    return contains(root, key);
}

void AVLTree::printTree(AVLNode* node, int space, std::ostream& os) const {
    if (!node) return;
    int COUNT = 5;
    space += COUNT;
    printTree(node->right, space, os);
    os << '\n';
    for (int i = COUNT; i < space; i++) os << " ";
    os << node->key << " (h:" << node->height << ")\n";
    printTree(node->left, space, os);
}

void AVLTree::print(std::ostream& os) const {
    if (!root) {
        os << "Дерево порожнє.\n";
        return;
    }
    printTree(root, 0, os);
    os << "\n";
}

int AVLTree::getRootKey() const {
    if (!root) throw std::out_of_range("Дерево порожнє");
    return root->key;
}

int AVLTree::getRootHeight() const {
    return height(root);
}

bool AVLTree::isEmpty() const {
    return root == nullptr;
}