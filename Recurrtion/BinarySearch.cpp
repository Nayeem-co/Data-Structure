#include<iostream>
#include<array>
using namespace std;


int BinarySearch(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = (l+r)/2;
        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] > x){
            return BinarySearch(arr, l, mid-1, x);
        }
        return BinarySearch(arr, mid+1, r, x);
    }
    return -1;
}

void useless(int arr[]){
    int x = (sizeof(arr) / sizeof(arr[0])) -1;
    cout<<"x: "<<x<<endl;
}

int nonRecursive(int arr[], int x){
    
    int r = (sizeof(arr) / sizeof(arr[0])) -1;
    cout<<"r : "<<r<<endl;
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
    int result = BinarySearch(arr, 0, 9, x);
    (result == -1)  ? cout<<"not found "<<endl
                    : cout<<result+1<<endl;

    cout<<".............."<<endl;

    cout<<".............."<<endl;

    int res = nonRecursive(arr,x);
    (res == -1)     ? cout<<"not found in non "<<endl
                    : cout<<res+1;


    int r = (sizeof(arr) / sizeof(arr[0])) -1;
    cout<<"r : "<<r<<endl;

    useless(arr);

    return 0;
}