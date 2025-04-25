// C++ program for expression tree
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

// An expression tree node
struct ETNode
{
    char value;
    ETNode* left, *right;
};

class ExpTree
{
    ETNode *root;
    void inorder(ETNode *ptr);
    bool isOperator(char);
    ETNode* newNode(char);
    float eval(ETNode*ptr);
public:
    void constructTree(string);
    float evaluate() { return eval(root); };
    void DisplayInOrder(){inorder(root);}
};



// Driver program to test above
int main()
{
    string postfix = "34+5*6-";//"ab+ef*g*-";
    ExpTree tree;
    //ETNode* r =
    tree.constructTree(postfix);
    cout<<"infix expression is \n";
    tree.DisplayInOrder();
    cout<<endl<<tree.evaluate();
    return 0;
}

// A utility function to check if 'c'
// is an operator
bool ExpTree::isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

// Utility function to do inorder traversal
void ExpTree::inorder(ETNode *t)
{
    if(t)
    {
        inorder(t->left);
        cout<<t->value;
        inorder(t->right);
    }
}

// A utility function to create a new node
ETNode* ExpTree::newNode(char v)
{
    ETNode *temp = new ETNode;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

// Returns root of constructed tree for given
// postfix expression
void ExpTree::constructTree(string postfix)
{
    stack<ETNode *> st;
    ETNode *t;

    // Traverse through every character of
    // input expression
    for (int i=0; i<postfix.length(); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);

            // Pop two top nodes
            t->right = st.top(); // Store top
            st.pop();	 // Remove top
            t->left = st.top();
            st.pop();

            // Add this subexpression to stack
            st.push(t);
        }
    }

    // only element will be root of expression
    // tree
    root = st.top();

}


float ExpTree::eval(ETNode *ptr)
{
    if(!ptr)
        return 0;
    if(!ptr->left && !ptr->right)
        return ptr->value - '0';
    int lvalue = eval(ptr->left);
    int rvalue = eval(ptr->right);

    if(ptr->value == '+')
        return lvalue+rvalue;
    if(ptr->value == '-')
        return lvalue-rvalue;
    if(ptr->value == '*')
        return lvalue*rvalue;
    if(ptr->value == '/')
        return lvalue/rvalue;
    if(ptr->value == '^')
        return pow(lvalue, rvalue);

}