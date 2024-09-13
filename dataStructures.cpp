#include <iostream>
#define MAX 1000

using namespace std;

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        std::cout << "Stack Overflow\n";
        return false;
    } else {
        arr[++top] = x;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        std::cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = arr[top--];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

#define SIZE 1000
class Queue {
    int front, rear;
    int arr[SIZE];

public:
    Queue() { front = rear = -1; }
    bool enqueue(int x);
    int dequeue();
    bool isEmpty();
};

bool Queue::enqueue(int x) {
    if (rear == SIZE - 1) {
        std::cout << "Queue Overflow\n";
        return false;
    } else {
        if (front == -1) front = 0;
        arr[++rear] = x;
        return true;
    }
}

int Queue::dequeue() {
    if (front == -1 || front > rear) {
        std::cout << "Queue Underflow\n";
        return 0;
    } else {
        int x = arr[front++];
        return x;
    }
}

bool Queue::isEmpty() {
    return (front == -1 || front > rear);
}

//Linked List
struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = nullptr; }
    void insert(int data);
    void display();
};

void LinkedList::insert(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}


//doubly LinkedList
struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;
};

class DoublyLinkedList {
    DoublyNode* head;

public:
    DoublyLinkedList() { head = nullptr; }
    void insert(int data);
    void display();
};

void DoublyLinkedList::insert(int data) {
    DoublyNode* newNode = new DoublyNode();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::display() {
    DoublyNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

//circular LinkedList
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
    CNode* head;

public:
    CircularLinkedList() { head = nullptr; }
    void insert(int data);
    void display();
};

void CircularLinkedList::insert(int data) {
    CNode* newNode = new CNode();
    newNode->data = data;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void CircularLinkedList::display() {
    if (head == nullptr) return;
    CNode* temp = head;
    do {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    std::cout << "HEAD\n";
}

//Stack implemented with doublyLinkedList
class StackDLL {
    DoublyNode* head;

public:
    StackDLL() { head = nullptr; }
    void push(int data);
    int pop();
    void display();
    bool isEmpty();
};

void StackDLL::push(int data) {
    DoublyNode* newNode = new DoublyNode();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

int StackDLL::pop() {
    if (head == nullptr) {
        std::cout << "Stack Underflow\n";
        return -1;
    }
    int data = head->data;
    DoublyNode* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return data;
}

bool StackDLL::isEmpty() {
    return head == nullptr;
}

void StackDLL::display() {
    DoublyNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

//Queue with doublyLinkedList
class QueueDLL {
    DoublyNode* front;
    DoublyNode* rear;

public:
    QueueDLL() {
        front = rear = nullptr;
    }
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    void display();
};

void QueueDLL::enqueue(int data) {
    DoublyNode* newNode = new DoublyNode();
    newNode->data = data;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
        newNode->prev = nullptr;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

int QueueDLL::dequeue() {
    if (front == nullptr) {
        std::cout << "Queue Underflow\n";
        return -1;
    }
    int data = front->data;
    DoublyNode* temp = front;
    front = front->next;
    if (front != nullptr) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }
    delete temp;
    return data;
}

bool QueueDLL::isEmpty() {
    return front == nullptr;
}

void QueueDLL::display() {
    DoublyNode* temp = front;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

//priority Queue
struct PNode {
    int data;
    int priority;
    PNode* next;
};

class PriorityQueue {
    PNode* front;

public:
    PriorityQueue() { front = nullptr; }
    void enqueue(int data, int priority);
    int dequeue();
    bool isEmpty();
    void display();
};

// Function to insert according to priority
void PriorityQueue::enqueue(int data, int priority) {
    PNode* newNode = new PNode();
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = nullptr;

    // If queue is empty or the new node has higher priority than the front
    if (front == nullptr || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        PNode* temp = front;

        // Traverse the list and find the position to insert
        while (temp->next != nullptr && temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to remove the element with the highest priority
int PriorityQueue::dequeue() {
    if (front == nullptr) {
        std::cout << "Priority Queue Underflow\n";
        return -1;
    } else {
        int data = front->data;
        PNode* temp = front;
        front = front->next;
        delete temp;
        return data;
    }
}

// Check if the queue is empty
bool PriorityQueue::isEmpty() {
    return front == nullptr;
}

// Function to display the priority queue
void PriorityQueue::display() {
    if (front == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    }
    PNode* temp = front;
    while (temp != nullptr) {
        std::cout << "(Data: " << temp->data << ", Priority: " << temp->priority << ") -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

//Binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() { root = nullptr; }
    void inorderTraversal(TreeNode* node);
    void preorderTraversal(TreeNode* node);
    void postorderTraversal(TreeNode* node);
};

// Inorder traversal (Left -> Root -> Right)
void BinaryTree::inorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

// Preorder traversal (Root -> Left -> Right)
void BinaryTree::preorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Postorder traversal (Left -> Right -> Root)
void BinaryTree::postorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << " ";
}


//Binary search Trees
class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() { root = nullptr; }
    void insert(int key);
    TreeNode* insertRec(TreeNode* node, int key);
    TreeNode* search(TreeNode* root, int key);
    void inorderTraversal(TreeNode* node);
    void PostTraversal(TreeNode* node);
    void PreorderTraversal(TreeNode* node);
};

// Recursive insert function
TreeNode* BinarySearchTree::insertRec(TreeNode* node, int key) {
    if (node == nullptr) return new TreeNode(key);

    if (key < node->data)
        node->left = insertRec(node->left, key);
    else if (key > node->data)
        node->right = insertRec(node->right, key);

    return node;
}

// Insert function (wrapper)
void BinarySearchTree::insert(int key) {
    root = insertRec(root, key);
}

// Search function
TreeNode* BinarySearchTree::search(TreeNode* node, int key) {
    if (node == nullptr || node->data == key) return node;

    if (key < node->data) return search(node->left, key);

    return search(node->right, key);
}

// Inorder traversal for Binary Search Tree
void BinarySearchTree::inorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

//Postorder traversal in Red-Black Tree
void BinarySearchTree::PostTraversal(TreeNode* node) {
    if (node == nullptr) return;
    PostTraversal(node->left);
    PostTraversal(node->right);
    std::cout << node->data << " ";
}

//Preorder traversal in Red-Black Tree
void BinarySearchTree::PreorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    PreorderTraversal(node->left);
    PreorderTraversal(node->right);
}

//red BlackTree
enum Color { RED, BLACK };

struct RBTreeNode {
    int data;
    bool color;
    RBTreeNode* left;
    RBTreeNode* right;
    RBTreeNode* parent;

    RBTreeNode(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    RBTreeNode* root;

protected:
    void rotateLeft(RBTreeNode*& node);
    void rotateRight(RBTreeNode*& node);
    void fixViolation(RBTreeNode*& node);

public:
    RedBlackTree() { root = nullptr; }
    void insert(int data);
    void inorderTraversal(RBTreeNode* node);
    void PreorderTraversal(RBTreeNode* node);
    void PostTraversal(RBTreeNode* node);
    RBTreeNode* getRoot() { return root; }
};

// Insertion function for Red-Black Tree
void RedBlackTree::insert(int data) {
    RBTreeNode* newNode = new RBTreeNode(data);

    if (root == nullptr) {
        newNode->color = BLACK;
        root = newNode;
    } else {
        RBTreeNode* temp = root;
        RBTreeNode* parent = nullptr;

        while (temp != nullptr) {
            parent = temp;
            if (data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        newNode->parent = parent;

        if (data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        fixViolation(newNode);
    }
}

// Left rotation utility
void RedBlackTree::rotateLeft(RBTreeNode*& node) {
    RBTreeNode* rightChild = node->right;
    node->right = rightChild->left;

    if (node->right != nullptr)
        node->right->parent = node;

    rightChild->parent = node->parent;

    if (node->parent == nullptr)
        root = rightChild;
    else if (node == node->parent->left)
        node->parent->left = rightChild;
    else
        node->parent->right = rightChild;

    rightChild->left = node;
    node->parent = rightChild;
}

// Right rotation utility
void RedBlackTree::rotateRight(RBTreeNode*& node) {
    RBTreeNode* leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != nullptr)
        node->left->parent = node;

    leftChild->parent = node->parent;

    if (node->parent == nullptr)
        root = leftChild;
    else if (node == node->parent->left)
        node->parent->left = leftChild;
    else
        node->parent->right = leftChild;

    leftChild->right = node;
    node->parent = leftChild;
}

// Fix Red-Black Tree violation after insertion
void RedBlackTree::fixViolation(RBTreeNode*& node) {
    RBTreeNode* parent = nullptr;
    RBTreeNode* grandparent = nullptr;

    while ((node != root) && (node->color != BLACK) && (node->parent->color == RED)) {
        parent = node->parent;
        grandparent = node->parent->parent;

        // Case A: Parent of node is left child of grandparent
        if (parent == grandparent->left) {
            RBTreeNode* uncle = grandparent->right;

            // Case 1: Uncle is red, recolor
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                // Case 2: node is right child, left rotate
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                // Case 3: node is left child, right rotate
                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            // Case B: Parent of node is right child of grandparent
            RBTreeNode* uncle = grandparent->left;

            // Case 1: Uncle is red, recolor
            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                // Case 2: node is left child, right rotate
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                // Case 3: node is right child, left rotate
                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }

    root->color = BLACK;
}

// Inorder traversal for Red-Black Tree
void RedBlackTree::inorderTraversal(RBTreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

//Postorder traversal in Red-Black Tree
void RedBlackTree::PostTraversal(RBTreeNode* node) {
    if (node == nullptr) return;
    PostTraversal(node->left);
    PostTraversal(node->right);
    std::cout << node->data << " ";
}

//Preorder traversal in Red-Black Tree
void RedBlackTree::PreorderTraversal(RBTreeNode* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    PreorderTraversal(node->left);
    PreorderTraversal(node->right);
}


int main() {
    // Binary Tree example
    BinaryTree bt;
    bt.root = new TreeNode(1);
    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(3);

    std::cout << "Inorder traversal of Binary Tree: ";
    bt.inorderTraversal(bt.root);
    std::cout << "\n";

    // Binary Search Tree example
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal of Binary Search Tree: ";
    bst.inorderTraversal

    (bst.root); std::cout << "\n";

    // Red-Black Tree example
    RedBlackTree rbt;
    rbt.insert(7);
    rbt.insert(3);
    rbt.insert(18);
    rbt.insert(10);
    rbt.insert(22);
    rbt.insert(8);
    rbt.insert(11);

    std::cout << "Inorder traversal of Red-Black Tree: ";
    rbt.inorderTraversal(rbt.getRoot());
    std::cout << "\n";

    return 0;
}