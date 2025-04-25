#include <iostream>
using namespace std;

class List {
    private:
        struct NodeType {
            float info;
            NodeType* next;
            NodeType* prev;  // Added for doubly linked list
        };
        NodeType* first;
        NodeType* last;
        int count;

    public:
        // Constructor
        List() {
            first = last = NULL;
            count = 0;
        }

        // Destructor
        ~List() {
            NodeType* current = first;
            while (current != NULL) {
                NodeType* temp = current;
                current = current->next;
                delete temp;
            }
        }

        // Insert node at the end
        void insertLast(float value) {
            NodeType* newNode = new NodeType;
            newNode->info = value;
            newNode->next = NULL;
            newNode->prev = last;  // Set previous pointer
            
            if (first == NULL) {
                first = last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
            count++;
        }

        // Insert node at the beginning
        void insertFirst(float value) {
            NodeType* newNode = new NodeType;
            newNode->info = value;
            newNode->next = first;
            newNode->prev = NULL;

            if (first == NULL) {
                first = last = newNode;
            } else {
                first->prev = newNode;
                first = newNode;
            }
            count++;
        }

        // Delete a node with specific value
        void deleteNode(float value) {
            NodeType* current = first;
            
            while (current != NULL) {
                if (current->info == value) {
                    if (current->prev != NULL) {
                        current->prev->next = current->next;
                    } else {
                        first = current->next;
                    }
                    
                    if (current->next != NULL) {
                        current->next->prev = current->prev;
                    } else {
                        last = current->prev;
                    }
                    
                    delete current;
                    count--;
                    return;
                }
                current = current->next;
            }
        }

        // Display list forward
        void displayForward() const {
            NodeType* current = first;
            while (current != NULL) {
                cout << current->info << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }

        // Display list backward
        void displayBackward() const {
            NodeType* current = last;
            while (current != NULL) {
                cout << current->info << " -> ";
                current = current->prev;
            }
            cout << "NULL" << endl;
        }

        // Get count of nodes
        int getCount() const {
            return count;
        }
};

int main() {
    List myList;

    // Test insertions
    myList.insertLast(10.5);
    myList.insertLast(20.5);
    myList.insertFirst(5.5);
    myList.insertLast(30.5);

    // Display forward
    cout << "List forward: ";
    myList.displayForward();

    // Display backward
    cout << "List backward: ";
    myList.displayBackward();

    // Delete a node
    myList.deleteNode(20.5);
    
    cout << "\nAfter deleting 20.5:" << endl;
    cout << "List forward: ";
    myList.displayForward();
    
    cout << "Number of nodes: " << myList.getCount() << endl;

    return 0;
}

