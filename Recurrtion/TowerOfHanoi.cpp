#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c){
    if(n == 0){
        cout<<"move disk "<<1<<" from "<<a<<" to "<<c<<endl;
        return;
    }
    towerOfHanoi(n-1,a,c,b);
    cout<<"move "<<n<<" th disk from "<<a<<" to "<<c<<endl;
    towerOfHanoi(n-1,b,a,c);
}


int main()
{
    int n ;
    cout<<"enter the size: ";
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B'); 

    cout<<"new //////////////////"<<endl;

    return 0;
}
 