#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void leftView(node * root){

    if(root == NULL){
        return;
    }
    queue<node*> Q;
    Q.push(root);

    while (!Q.empty()){
        node * curr = Q.front();
        int n = Q.size();

        for(int i=0 ; i< n ; i++){
            if(i == 0){
                cout<<curr->data<<" ";
            }
            Q.pop();
        }
        if(curr->left != NULL){
            Q.push(curr->left);
        }
        if(curr->right != NULL){
            Q.push(curr->right);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3); 

    root->left->left = new node(4);
    root->left->right = new node (10);
    root->right->right = new node(5);
    root->right->left = new node (90);

    leftView(root);

    return 0;
}
