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


void preoderPrint(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preoderPrint(root->left);
    preoderPrint(root->right);
}

void inoderprint(node * root){
    if(root == NULL){
        return;
    }
    inoderprint(root->left);
    cout<<root->data<<" ";
    inoderprint(root->right);
}

void postoderPrint(node * root){
    if(root == NULL){
        return;
    }
    postoderPrint(root->left);
    postoderPrint(root->right);
    cout<<root->left<<" ";
}

node * Search(node * root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return Search(root->left,key);
    }
    return Search(root->right,key);
}


int main(int argc, char const *argv[]){

    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4); 

    root->left->left = new node(1);
    root->right->right = new node(5);

    if(Search(root,5)){
        cout<<Search(root,5)->data<<endl;
    }
    else{
        cout<<"not found "<<endl;
    }
    
    
    return 0;
}
