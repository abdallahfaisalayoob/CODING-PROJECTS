

bool searchtree(int num){
    treenode * current=root;

    while(current){
        if(num==current->value){
            return true;

        } else if( num<current->value)
        {
            current=current->left;

        } else if (num> current->value) {
            current=current->right;
        
        }
        }
        return false;
        }
    }
}

void insertnode(int num){

    treenode * newnode, current;

    current=root;
    
    newnode->value= num;
    newnode->left=newnode->right=NULL;

    if(!root){
        root=newnode;
    } else{

        while(current!=NULL){
            if(num<current->value){
                if(current->left){
                    current=current->left;
                } else{
                    current->left=newnode;
                    break;
                }
            }
        }
            else if{num>current->value}{
                if(current->right){
                    current=current->right;
                }
                else {
                    current->right=newnode;
                    break;
                }
            }
            
    }
}]


struct node *insert(node*node, int key){
    if(key<node->key){
        node->left=insert(node->left,key);
    } else
    {
        node->right=insert(node->right, key);
    }
    return node;
}