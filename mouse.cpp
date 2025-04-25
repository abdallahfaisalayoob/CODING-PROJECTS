#include <iostream>
using namespace std;

class Mouse {
private:
    bool forward;
    bool backward;
    bool leftSide;
    bool rightSide;
    bool leftClick;
    bool rightClick;

public:
    // Constructor to initialize all boolean values to false
    Mouse() : forward(false), backward(false), leftSide(false), rightSide(false), leftClick(false), rightClick(false) {}

    // Setter methods
    void setForward(bool state) { forward = state; }
    void setBackward(bool state) { backward = state; }
    void setLeftSide(bool state) { leftSide = state; }
    void setRightSide(bool state) { rightSide = state; }
    void setLeftClick(bool state) { leftClick = state; }
    void setRightClick(bool state) { rightClick = state; }

    // Getter methods
    bool isForward() const { return forward; }
    bool isBackward() const { return backward; }
    bool isLeftSide() const { return leftSide; }
    bool isRightSide() const { return rightSide; }
    bool isLeftClick() const { return leftClick; }
    bool isRightClick() const { return rightClick; }

    // Print current state
    void printState() const {
        cout << "Mouse State: \n";
        cout << "Forward: " << (forward ? "ON" : "OFF") << "\n";
        cout << "Backward: " << (backward ? "ON" : "OFF") << "\n";
        cout << "Left Side: " << (leftSide ? "ON" : "OFF") << "\n";
        cout << "Right Side: " << (rightSide ? "ON" : "OFF") << "\n";
        cout << "Left Click: " << (leftClick ? "ON" : "OFF") << "\n";
        cout << "Right Click: " << (rightClick ? "ON" : "OFF") << "\n";
    }
};

int main() {
    Mouse myMouse;
    
    // Set some values
    myMouse.setForward(true);
    myMouse.setLeftClick(true);
    
    // Print the state of the mouse
    myMouse.printState();

    return 0;
}