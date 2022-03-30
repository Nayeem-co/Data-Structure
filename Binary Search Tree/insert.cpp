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

node *  insertBST(node * root, int val){
    
    if(root == NULL){
        return new node(val);
    }
    if(val < root->data){
       root-> left = insertBST(root->left,val); 
    }
    else{
        root->right = insertBST(root->right,val);
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

int main(int argc, char const *argv[])
{
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4); 

    root->left->left = new node(1);
    root->right->right = new node(5);


    inoderPrint(root);

    
    return 0;
}
