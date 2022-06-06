#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int k=(2*n-1+2)/3;
    int diag=(n-k)*2-1;
    cout<<k<<endl;
    for(int i=k+1;i<=n;i++)
        cout<<n-(i-1-k)<<' '<<i<<endl;
    if(diag==k)
        for(int i=k;i>n-k;i--)
            cout<<i<<' '<<n-i+1<<endl;
    else{
        if(3*k-(2*n-1)==1){
            for(int i=k;i>n-k+1;i--)
                cout<<i<<' '<<n-i+2<<endl;
            cout<<n-k+1<<' '<<n-k+1<<endl;
        }
        else
            for(int i=k;i>n-k;i--)
                cout<<i<<' '<<n-i+1<<endl;
    }
    return 0;
}