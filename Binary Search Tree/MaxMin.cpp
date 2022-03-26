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

node * Max(node * root){
    if(root->right == NULL){
        return root;
    }
    else{
        return Max(root->right);
    }
}

node* Min(node * root){
    if(root->left == NULL){
        return root;
    }
    else{
        return Min(root->left);
    }
}


int main(int argc, char const *argv[]){

    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4); 

    root->left->left = new node(1);
    root->right->right = new node(5);

    cout<<"max : "<<Max(root)->data<<endl;

    cout<<"min : "<<Min(root)->data<<endl;
    
    return 0;
}
