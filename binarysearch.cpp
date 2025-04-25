#include <iostream>
using namespace std;
struct TreeNode {
        int value;
        TreeNode *left, *right;
    };

class IntBinaryTree
{

    TreeNode *root;
    void displayIO(TreeNode*);
    struct TreeNode* Delete(struct TreeNode *, int);
    int countLeaves(TreeNode*);
public:
    IntBinaryTree()
        { root=NULL; }
    void insertNode(int);
    void showNodesIO()
        { displayIO(root); }
    void callDelete(int key)
        { root = Delete(root,key); }
    TreeNode* FindMin(TreeNode*);

    int countL()
    {   return countLeaves(root);   }

};

int main()
{
    IntBinaryTree tree;
    tree.insertNode(45);
    tree.insertNode(5);
    tree.insertNode(35);
    tree.insertNode(76);
    tree.insertNode(3);
    tree.insertNode(928);
    tree.insertNode(63);
    tree.insertNode(20);
    tree.insertNode(15);
    tree.insertNode(25);
    tree.showNodesIO();
    cout<<endl;

    cout<<"No of Leaf nodes are :"<<tree.countL()<<endl;

    tree.callDelete(35);
    tree.showNodesIO();

}

int IntBinaryTree::countLeaves(TreeNode *ptr){
    if(!ptr)
        return 0;
    else if(!ptr->left && !ptr->right)
        return 1;
    return countLeaves(ptr->left) + countLeaves(ptr->right);

}



void IntBinaryTree::insertNode(int num)
{
    TreeNode *nptr, *curr;
    nptr = new TreeNode;
    nptr->value = num;
    nptr->left = nptr->right = NULL;

    if(!root)
        root = nptr;
    else
    {
        curr = root;
        while(curr!=NULL)
        {
            if(num < curr->value) {
                if(curr->left)
                    curr = curr->left;
                else {
                    curr->left = nptr;
                    break;
                }
            }
            else if(num > curr->value) {
                if(curr->right)
                    curr = curr->right;
                else {
                    curr->right = nptr;
                    break;
                }
            }
            else {
                cout<<"Duplicate value not allowed";
                break;
            }
        }

    }
}

void IntBinaryTree::displayIO(TreeNode* ptr){
    if(ptr){
        displayIO(ptr->left);
        cout<<ptr->value<<"  ";
        displayIO(ptr->right);
    }
}

struct TreeNode* IntBinaryTree::Delete(struct TreeNode *ptr, int data) {
	if(ptr == NULL) return ptr;
	else if(data < ptr->value)
        ptr->left = Delete(ptr->left,data);
	else if (data > ptr->value)
        ptr->right = Delete(ptr->right,data);
	// Wohoo... I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if(ptr->left == NULL && ptr->right == NULL) {
			delete ptr;
			ptr = NULL;
		}
		//Case 2: One child
		else if(ptr->left == NULL) {
			struct TreeNode *temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
		else if(ptr->right == NULL) {
			struct TreeNode *temp = ptr;
			ptr = ptr->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct TreeNode *temp = FindMin(ptr->right);
			ptr->value = temp->value;
			ptr->right = Delete(ptr->right,temp->value);
		}
	}
	return ptr;
}

TreeNode* IntBinaryTree::FindMin(TreeNode *ptr)
{
    while(ptr->left)
        ptr=ptr->left;
    return ptr;
}