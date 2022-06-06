#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;

void solve() {
    LL x;
    cin>>x;
    if(x==1) {
        cout<<3<<endl;
        return;
    }
    LL y=lowbit(x);
    if(y!=x) cout<<y<<endl;
    else cout<<(y|1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}