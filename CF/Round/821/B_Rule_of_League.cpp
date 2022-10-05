#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    if(x<y) swap(x,y);
    if(x&&y||!x&&!y||(n-1)%x) {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=2,cnt=0,cur=1;i<=n;i++) {
        cout<<cur<<" ";
        if(++cnt==x) cnt=0,cur=i+1;        
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