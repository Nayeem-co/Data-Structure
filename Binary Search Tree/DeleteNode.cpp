#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node * left;
    node * right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

node * inoderSucc(node* root){
    node * curr = root;
    while (curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

node * deleteBST(node * root, int key){
    if (root == NULL){
        return root;
    }
    if(key < root->data){
        root->left = deleteBST(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteBST(root->right,key);
    }
    else{
        if(root->left == NULL){
            node* temp = root->right;
            delete (root);
            return temp;
        }
        else if(root->right == NULL){
            node * temp = root->left;
            delete(root);
            return temp;
        }
        else{
            node * temp = inoderSucc(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;
}


void inoderPrint(node * root){
    if(root == NULL){
        return;
    }
    inoderPrint(root->left);
    cout<<root->data<<" ";
    inoderPrint(root->right);
}

int main(int argc, char const *argv[]){
    
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4); 

    root->left->left = new node(1);
    root->right->right = new node(5);

    inoderPrint(root);
    cout<<endl;

    root = deleteBST(root,1);
    inoderPrint(root);

    root = deleteBST(root,5);
    inoderPrint(root);

    root = deleteBST(root,3);
    inoderPrint(root);
    return 0;
}
