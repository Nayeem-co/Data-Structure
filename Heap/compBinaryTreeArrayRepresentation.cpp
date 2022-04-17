#include<iostream>
using namespace std;

class node {
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

void insert(int *arr,int val){
    if(arr == NULL){
        *arr = val;
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[10];
    insert(arr,5);


    return 0;
}
