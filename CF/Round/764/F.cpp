#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    int n,x,last=0,add=0;
    cin>>n;
    int l=1,r=n-1,mid;
    while(l<r){
        mid=l+r>>1;
        int q=n-(mid+1+add)%n;
        add+=q;
        cout<<"+ "<<q<<endl;
        cin>>x;
        if(x>last) l=mid+1;
        else r=mid;
        last=x;
    }
    cout<<"! "<<l+add<<endl;
    return 0;
}