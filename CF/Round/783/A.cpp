#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n==1&&m==1){
            cout<<0<<endl;
            continue;
        }
        else if(n==1&&m==2||n==2&&m==1){
            cout<<1<<endl;
            continue;
        }
        else if(n==1||m==1){
            cout<<-1<<endl;
            continue;
        }
        else if(n==m){
            cout<<n+m-2<<endl;
            continue;
        }
        if(n<m) swap(n,m);
        int t=n-m;
        if(t&1) cout<<(n+m-2)+(t-1)<<endl;
        else cout<<(n+m-2)+t<<endl;
    }
    return 0;
}