#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<LL,LL>;
const int N=2e5+10;
LL a[N],b[N];

void solve() {
    int n,k;
    LL m;
    cin>>n>>m;
    deque<PII> dq;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        LL t=1;
        while(a[i]%(t*m)==0) t*=m;
        if(dq.size()&&dq.back().first==a[i]/t) dq.back().second+=t;
        else dq.emplace_back(a[i]/t,t);
    }
    cin>>k;
    for(int i=1;i<=k;i++) cin>>b[i];
    bool ans=0;
    for(int i=1;i<=k;i++) {
        if(dq.size()&&b[i]%dq.front().first==0) {
            LL t=b[i]/dq.front().first;
            LL bak=t;
            while(bak>1&&bak%m==0) bak/=m;
            if(bak==1&&dq.front().second>=t) {
                dq.front().second-=t;
                if(dq.front().second==0) dq.pop_front();
            }
            else break;
            if(dq.empty()&&i==k) ans=1;
        }
        else break;
    }
    cout<<(ans?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}