#include<iostream>
using namespace std;


int nonRecursive(int arr[], int x){
    
    int r = 9;
    int l = 0;
    
    while(r >= l){
        int mid = (l+r)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] > x){
            r = mid -1;
        }
        else if(arr[mid] < x){
            l = mid + 1;
        }
    }
    return -1;

}


int main(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int x ;
    cin>>x;

    if(nonRecursive(arr,x) != -1){
        cout<<nonRecursive(arr,x)+1;
    }
    else{
        cout<<"brhfbau";
    }

    return 0;
}