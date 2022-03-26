#include<iostream>
using namespace std;

class node {
    public:
    char value;
    node * left;
    node * right;

    node(char a){
        value = a;
        left = NULL;
        right = NULL;
    }
};

int search(char inoder[], int start, int end, char val){
    for(int i=start; i<=end ; i++){
        if(inoder[i] == val){
            return i;
        }
    }
    return -1;
}

node * buildTree(char preoder[], char inoder[], int start, int end){

    static int idx = 0;
    if(start > end){
        return NULL;
    }
    int curr = preoder[idx];
    idx++;
    node * n = new node(curr);
    if(start == end){
        return n;
    }
    int pos = search(inoder,start, end, curr);
    n->left = buildTree(preoder,inoder,start,pos-1);
    n->right = buildTree(preoder,inoder,pos+1,end);

    return n;
}

void postOderPrint(node * root){
    if(root == NULL){
        return;
    }
    postOderPrint(root->left);
    postOderPrint(root->right);
    cout<<root->value<<" ";
}

void preoderPrint(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->value<<" ";
    preoderPrint(root->left);
    preoderPrint(root->right);
}
int main(){

    char preoder[]  = {'A','B','D','E','C','F','G'};
    char inoder[]   = {'D','B','E','A','F','C','G'};

    node * root = buildTree(preoder,inoder,0,6);
    cout<<"printing in postoder: ";
    postOderPrint(root);
    cout<<endl;
    cout<<"pinting in preoder :";
    preoderPrint(root);
    cout<<endl;
    return 0;
}