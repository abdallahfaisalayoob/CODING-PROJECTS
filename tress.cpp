#include <iostream>
using namespace std;

// Define the tree node structure
struct treenode {
    int value;
    treenode* left;
    treenode* right;

    // Constructor for creating a new node
    treenode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into the tree
treenode* insert(treenode* root, int value) {
    if (root == nullptr) {
        return new treenode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root; // Return the unchanged root pointer
}

// In-order traversal (Left, Root, Right)
void inorder(treenode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(treenode* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(treenode* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

// Build a binary tree from an array of values
treenode* buildTree(int arr[], int size) {
    treenode* root = nullptr;
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

int main() {
    // Example usage
    int arr[] = {30, 15, 50, 10, 20, 40, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Build the binary tree
    treenode* root = buildTree(arr, size);

    // Perform traversals
    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
