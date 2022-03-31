#include<iostream>
#include<array>
using namespace std;

int sumofArr(int arr[], int n){
    if(n == -1){
        return 0;
    }
    int sum = 0;
    return sum = sum + arr[n] + sumofArr(arr,n-1);
}


int main(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<sumofArr(arr,9)<<endl;
    int sum = 0;
    for(int i=0 ; i<10; i++){
        sum = sum + arr[i];
    }
    cout<<sum;

    return 0;
}