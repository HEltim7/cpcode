#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e3+10;
int sg[N];
bool mark[N];
PII pre[N][N];
vector<PII> seg;

void mimic(int n) {
    int l,r;
    while(cin>>l>>r&&l>=1&&r>=1) {
        r=l+r-1;
        if(l<=n/2) cout<<n-r+1<<' '<<r-l+1<<endl;
        else cout<<n-r+1<<' '<<r-l+1<<endl;
    }
}

int split(int l,int r) {
    int res=0;
    for(auto it=seg.begin();it!=seg.end();it++) {
        auto [L,R]=*it;
        if(l>=L&&r<=R) {
            int llen=l-L;
            int rlen=R-r;
            res=sg[R-L+1]^sg[llen]^sg[rlen];
            seg.erase(it);
            if(llen) seg.emplace_back(L,l-1);
            if(rlen) seg.emplace_back(r+1,R);
            break;
        }
    }
    return res;
}

PII find(int val) {
    PII res;
    for(auto it=seg.begin();it!=seg.end();it++) {
        auto [L,R]=*it;
        int len=R-L+1;
        if((sg[len]^val)<=sg[len]) {
            auto [l,r]=pre[len][val^sg[len]];
            res={L+l,R-r};
            seg.erase(it);
            if(l) seg.emplace_back(L,L+l-1);
            if(r) seg.emplace_back(R-r+1,R);
            break;
        }
    }
    return res;
}

void interactive() {
    int l,r;
    while(cin>>l>>r&&l>=1&&r>=1) {
        auto [L,R]=find(split(l, l+r-1));
        cout<<L<<' '<<R-L+1<<endl;
    }
}

void solve() {
    int n,l,r;
    cin>>n>>l>>r;
    if(l!=r||n%2==r%2) {
        cout<<"First"<<endl;
        int x=l;
        if(n%2!=l%2) x=l+1;
        int mid=(n+1)/2;
        if(n&1) cout<<mid-x/2<<' '<<x<<endl;
        else cout<<mid-x/2+1<<' '<<x<<endl;
        mimic(n);
        return;
    }
    
    for(int i=l;i<=n;i++) {
        vector<int> cur;
        for(int L=0,R=i-l-L;R>=0;L++,R--) {
            int s=sg[L]^sg[R];
            mark[s]=1;
            cur.push_back(s);
            pre[i][s]={L,R};
        }
        for(int j=i;j>=0;j--) if(!mark[j]) sg[i]=j;
        for(auto s:cur) mark[s]=0;
    }

    seg.emplace_back(1,n);
    if(sg[n]) {
        cout<<"First"<<endl;
        auto [l,r]=find(sg[n]);
        cout<<l<<' '<<r-l+1<<endl;
    }
    else cout<<"Second"<<endl;
    interactive();
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}