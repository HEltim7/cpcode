#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int hbit(int x){
    int res=-1;
    while(x) res++,x>>=1;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int y=1<<hbit(n-1);
        for(int i=1;i<y;i++) cout<<i<<' ';
        cout<<0<<' ';
        for(int i=y;i<n;i++) cout<<i<<" \n"[i==n-1];
    }
    return 0;
}