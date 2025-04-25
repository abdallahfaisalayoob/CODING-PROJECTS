#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;

class StackOperations {
private:
    stack<int> s;
public:
    void push(int x) {
        s.push(x);
        cout << "Pushed: " << x << endl;
    }
    
    void pop() {
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Popped: " << s.top() << endl;
        s.pop();
    }
    
    void display() {
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        stack<int> temp = s;
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

class QueueOperations {
private:
    queue<int> q;
public:
    void enqueue(int x) {
        q.push(x);
        cout << "Enqueued: " << x << endl;
    }
    
    void dequeue() {
        if (q.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << q.front() << endl;
        q.pop();
    }
    
    void display() {
        if (q.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        queue<int> temp = q;
        cout << "Queue elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

class ListOperations {
private:
    list<int> l;
public:
    void insertFront(int x) {
        l.push_front(x);
        cout << "Inserted at front: " << x << endl;
    }
    
    void insertBack(int x) {
        l.push_back(x);
        cout << "Inserted at back: " << x << endl;
    }
    
    void removeFront() {
        if (l.empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Removed from front: " << l.front() << endl;
        l.pop_front();
    }
    
    void removeBack() {
        if (l.empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Removed from back: " << l.back() << endl;
        l.pop_back();
    }
    
    void display() {
        if (l.empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "List elements: ";
        for (int x : l) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    StackOperations stack;
    QueueOperations queue;
    ListOperations list;
    
    int choice, subchoice, value;
    
    while (true) {
        cout << "\nChoose Data Structure:" << endl;
        cout << "1. Stack" << endl;
        cout << "2. Queue" << endl;
        cout << "3. List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 4) break;
        
        switch (choice) {
            case 1: // Stack operations
                while (true) {
                    cout << "\nStack Operations:" << endl;
                    cout << "1. Push" << endl;
                    cout << "2. Pop" << endl;
                    cout << "3. Display" << endl;
                    cout << "4. Back to main menu" << endl;
                    cout << "Enter choice: ";
                    cin >> subchoice;
                    
                    if (subchoice == 4) break;
                    
                    switch (subchoice) {
                        case 1:
                            cout << "Enter value to push: ";
                            cin >> value;
                            stack.push(value);
                            break;
                        case 2:
                            stack.pop();
                            break;
                        case 3:
                            stack.display();
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                }
                break;
                
            case 2: // Queue operations
                while (true) {
                    cout << "\nQueue Operations:" << endl;
                    cout << "1. Enqueue" << endl;
                    cout << "2. Dequeue" << endl;
                    cout << "3. Display" << endl;
                    cout << "4. Back to main menu" << endl;
                    cout << "Enter choice: ";
                    cin >> subchoice;
                    
                    if (subchoice == 4) break;
                    
                    switch (subchoice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            queue.enqueue(value);
                            break;
                        case 2:
                            queue.dequeue();
                            break;
                        case 3:
                            queue.display();
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                }
                break;
                
            case 3: // List operations
                while (true) {
                    cout << "\nList Operations:" << endl;
                    cout << "1. Insert at front" << endl;
                    cout << "2. Insert at back" << endl;
                    cout << "3. Remove from front" << endl;
                    cout << "4. Remove from back" << endl;
                    cout << "5. Display" << endl;
                    cout << "6. Back to main menu" << endl;
                    cout << "Enter choice: ";
                    cin >> subchoice;
                    
                    if (subchoice == 6) break;
                    
                    switch (subchoice) {
                        case 1:
                            cout << "Enter value to insert at front: ";
                            cin >> value;
                            list.insertFront(value);
                            break;
                        case 2:
                            cout << "Enter value to insert at back: ";
                            cin >> value;
                            list.insertBack(value);
                            break;
                        case 3:
                            list.removeFront();
                            break;
                        case 4:
                            list.removeBack();
                            break;
                        case 5:
                            list.display();
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                }
                break;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}

