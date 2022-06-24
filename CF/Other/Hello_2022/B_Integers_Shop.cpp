#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    LL L,Lc,R,Rc;
    LL len=0,slen=0,cost=0;
    for(int i=1;i<=n;i++) {
        LL l,r,c;
        cin>>l>>r>>c;
        if(i==1||l<L||l==L&&c<=Lc) L=l,Lc=c;
        if(i==1||r>R||r==R&&c<=Rc) R=r,Rc=c;
        if(r-l+1>slen||r-l+1==slen&&c<cost) slen=r-l+1,cost=c;
        len=max(len,R-L+1);
        if(len==slen) cout<<min(cost,Lc+Rc)<<endl;
        else cout<<Lc+Rc<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}