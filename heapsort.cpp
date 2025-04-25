#include <iostream>
using namespace std;

class HeapSort {
private:
    // Helper function to swap two elements
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Heapify a subtree rooted at index 'root'
    void heapify(int arr[], int size, int root) {
        // Initialize largest as root
        int largest = root;
        int left = 2 * root + 1;   // Left child
        int right = 2 * root + 2;   // Right child

        // If left child is larger than root
        if (left < size && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < size && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != root) {
            swap(arr[root], arr[largest]);
            // Recursively heapify the affected sub-tree
            heapify(arr, size, largest);
        }
    }

public:
    void sort(int arr[], int size) {
        // Build heap (rearrange array)
        // Start from last non-leaf node and move upwards
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(arr, size, i);

        // Extract elements from heap one by one
        for (int i = size - 1; i > 0; i--) {
            // Move current root (maximum element) to end
            swap(arr[0], arr[i]);
            // Call heapify on the reduced heap
            heapify(arr, i, 0);
        }
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

    HeapSort heapSort;
    cout << "Original array: ";
    heapSort.printArray(arr, n);

    heapSort.sort(arr, n);

    cout << "Sorted array: ";
    heapSort.printArray(arr, n);
    return 0;
}
