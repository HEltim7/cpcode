#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    int cnt=0,res=1e9;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in&1) res=0;
        else {
            int cur=0;
            cnt++;
            while(in%2==0) {
                in/=2;
                cur++;
            }
            res=min(res,cur);
        }
    }
    if(res==0) cout<<cnt<<endl;
    else cout<<res+cnt-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}