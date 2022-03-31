#include<iostream>
using namespace std;

int comb(int n, int r){
    if(n == r){
        return 1;
    }
    else if( r == 1){
        return n;
    }
    return (comb(n-1,r)+comb(n-1,r-1));
}

int main(int argc, char const *argv[])
{
    int n,r;
    cin>>n>>r;

    cout<<comb(n,r);
    return 0;
}
