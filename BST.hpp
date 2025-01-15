#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
} Node;

/**
 * @class BinaryTree
 * @brief A class to represent a binary search tree (BST).
 */
class BinaryTree {
public:
    Node* ROOT = NULL; // Root node of the binary tree

    Node* insertNode(Node* root, int data);       // Insert a node
    void deleteNode(int value);                  // Delete a node
    void preOrderTraversal(Node* root);          // Pre-order traversal
    void sortedArrayToBalancedBST(Node*& root, vector<int>& nodeValues, int start, int end);
    void balanceBST(Node*& root);                // Balance the BST
    void printTree(Node* root, string prefix = "", bool isLeft = true); // Print tree structure
    void inOrderStorage(Node* root, vector<int>& nodeValues); // Store in-order traversal

private:
    Node* deleteNodeHelper(Node* root, int value); // Recursive helper for deletion
    Node* findMin(Node* root);                     // Find the in-order successor
};

// Insert a node into the binary tree
Node* BinaryTree::insertNode(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->leftChild = insertNode(root->leftChild, data);
    } else {
        root->rightChild = insertNode(root->rightChild, data);
    }
    return root;
}

// Recursive function to delete a node
Node* BinaryTree::deleteNodeHelper(Node* root, int value) {
    if (root == NULL) {
        cout << "Value " << value << " not found in the tree." << endl;
        return root;
    }

    if (value < root->data) {
        root->leftChild = deleteNodeHelper(root->leftChild, value);
    } else if (value > root->data) {
        root->rightChild = deleteNodeHelper(root->rightChild, value);
    } else {
        // Node to delete found
        if (root->leftChild == NULL && root->rightChild == NULL) {
            delete root;
            return NULL;
        }

        if (root->leftChild == NULL) {
            Node* temp = root->rightChild;
            delete root;
            return temp;
        }

        if (root->rightChild == NULL) {
            Node* temp = root->leftChild;
            delete root;
            return temp;
        }

        Node* successor = findMin(root->rightChild);
        root->data = successor->data;
        root->rightChild = deleteNodeHelper(root->rightChild, successor->data);
    }
    return root;
}

// Find the in-order successor (smallest node in the subtree)
Node* BinaryTree::findMin(Node* root) {
    while (root->leftChild != NULL) {
        root = root->leftChild;
    }
    return root;
}

// Delete a node from the binary tree
void BinaryTree::deleteNode(int value) {
    ROOT = deleteNodeHelper(ROOT, value);
}

// Pre-order traversal
void BinaryTree::preOrderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

// Convert a sorted array to a balanced binary search tree
void BinaryTree::sortedArrayToBalancedBST(Node*& root, vector<int>& nodeValues, int start, int end) {
    if (start > end) return;

    int median = (start + end) / 2;
    Node* newNode = new Node;
    newNode->data = nodeValues[median];
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    root = newNode;

    sortedArrayToBalancedBST(root->leftChild, nodeValues, start, median - 1);
    sortedArrayToBalancedBST(root->rightChild, nodeValues, median + 1, end);
}

// Store in-order traversal in a vector
void BinaryTree::inOrderStorage(Node* root, vector<int>& nodeValues) {
    if (root != NULL) {
        inOrderStorage(root->leftChild, nodeValues);
        nodeValues.push_back(root->data);
        inOrderStorage(root->rightChild, nodeValues);
    }
}

// Balance the binary search tree
void BinaryTree::balanceBST(Node*& root) {
    vector<int> nodeValuesInOrder;
    inOrderStorage(root, nodeValuesInOrder);
    sortedArrayToBalancedBST(root, nodeValuesInOrder, 0, nodeValuesInOrder.size() - 1);
}

// Print the tree structure
void BinaryTree::printTree(Node* root, string prefix, bool isLeft) {
    if (root != NULL) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──");
        cout << root->data << endl;

        printTree(root->leftChild, prefix + (isLeft ? "│   " : "    "), true);
        printTree(root->rightChild, prefix + (isLeft ? "│   " : "    "), false);
    }
}

// // Main Function
// int main() {
//     BinaryTree tree;

//     // Create a sorted array
//     vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7};

//     // Build a balanced BST from the array
//     tree.sortedArrayToBalancedBST(tree.ROOT, sortedArray, 0, sortedArray.size() - 1);

//     cout << "Initial Balanced Binary Search Tree:" << endl;
//     tree.printTree(tree.ROOT);
//     cout << endl;

//     // Insert a new node
//     cout << "Inserting a new node with value 8:" << endl;
//     tree.ROOT = tree.insertNode(tree.ROOT, 8);
//     tree.printTree(tree.ROOT);
//     cout << endl;

//     // Delete a leaf node
//     cout << "Deleting a leaf node (7):" << endl;
//     tree.deleteNode(7);
//     tree.printTree(tree.ROOT);
//     cout << endl;

//     // Delete a node with one child
//     cout << "Deleting a node with one child (6):" << endl;
//     tree.deleteNode(6);
//     tree.printTree(tree.ROOT);
//     cout << endl;

//     // Delete a node with two children
//     cout << "Deleting a node with two children (4):" << endl;
//     tree.deleteNode(4);
//     tree.printTree(tree.ROOT);
//     cout << endl;

//     return 0;
// }