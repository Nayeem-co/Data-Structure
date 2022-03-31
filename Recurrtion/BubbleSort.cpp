#include<iostream>
#include <bits/stdc++.h>
#include<array>
using namespace std;


int main(){

    int n = 10;
    int arr[n] = {10,9,8,7,6,5,2,3,4,10};
    int a = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0 ; i< a-1 ; i++ ){
        for(int j=0 ; j< a-1-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0 ; i< a; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}