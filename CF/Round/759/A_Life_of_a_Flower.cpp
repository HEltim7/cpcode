#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,ans=1;
    cin>>n;
    bool flag=1;
    for(int i=1,last=0;i<=n;i++) {
        int in;
        cin>>in;
        if(in==1) {
            if(last==1) ans+=5;
            else ans++;
        }
        else if(i!=1&&last==0) {
            flag=0;
        }
        last=in;
    }
    if(flag) cout<<ans<<endl;
    else cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}