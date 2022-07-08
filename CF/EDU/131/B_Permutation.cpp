#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;

const int M=2e5+10;
bool mark[M];

void solve() {
    int n;
    cin>>n;
    memset(mark,0,sizeof (bool)*(n+1));
    cout<<2<<endl;
    for(int i=1;i<=n;i++) {
        if(mark[i]) continue;
        for(int j=1;j*i<=n;j*=2) {
            mark[j*i]=1;
            cout<<i*j<<' ';
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}