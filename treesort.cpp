#include <iostream>
using namespace std;

class TreeSort {
private:
    // Node structure for BST
    struct Node {
        int data;
        Node* left;
        Node* right;
        
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    // Helper function to insert into BST
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
            
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
            
        return node;
    }
    
    // Helper function for in-order traversal
    void inorderTraversal(Node* node, int arr[], int& index) {
        // Base case: if we reach a null node, stop recursion
        if (node == nullptr)
            return;
        
        // 1. First recursively traverse left subtree
        inorderTraversal(node->left, arr, index);
        
        // 2. Process current node: store its value in array and increment index
        arr[index++] = node->data;
        
        // 3. Finally recursively traverse right subtree
        inorderTraversal(node->right, arr, index);
    }
    
    // Helper function to delete the tree
    void deleteTree(Node* node) {
        // Base case: if we reach a null node, stop recursion
        if (node == nullptr)
            return;
        
        // 1. First delete left subtree
        deleteTree(node->left);
        
        // 2. Then delete right subtree
        deleteTree(node->right);
        
        // 3. Finally delete current node (post-order traversal)
        delete node;
    }

public:
    TreeSort() : root(nullptr) {}
    
    ~TreeSort() {
        deleteTree(root);
    }
    
    void sort(int arr[], int size) {
        // Create BST from array elements
        root = nullptr;
        for (int i = 0; i < size; i++) {
            root = insert(root, arr[i]);
        }
        
        // Perform in-order traversal to get sorted array
        int index = 0;
        inorderTraversal(root, arr, index);
    }
    
    // Utility function to print array
    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    TreeSort treeSort;
    cout << "Original array: ";
    treeSort.printArray(arr, n);
    
    treeSort.sort(arr, n);
    
    cout << "Sorted array: ";
    treeSort.printArray(arr, n);
    return 0;
}
