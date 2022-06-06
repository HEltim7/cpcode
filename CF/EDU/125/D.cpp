#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10,M=1e6+10;
const LL INF=1e18;
LL ans[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,C;
    cin>>n>>C;
    map<int,LL> tmp;
    for(int i=1;i<=n;i++){
        int c,d,h;
        cin>>c>>d>>h;
        auto it=tmp.find(c);
        if(it==tmp.end()) tmp.insert({c,1LL*d*h});
        else if(1LL*d*h>it->second) it->second=1LL*d*h;
    }
    for(auto [c,dh]:tmp)
        for(int i=1;i<=C/c&&dh<=INF/i;i++)
            ans[c*i]=max(ans[c*i],dh*i);
    ans[1000001]=INF+1;
    for(int i=1;i<M;i++) ans[i]=max(ans[i-1],ans[i]);

    cin>>m;
    while(m--){
        LL d,h;
        cin>>d>>h;
        LL q=d*h;
        int l=1,r=1e6+1;
        while(l<r){
            int mid=l+r>>1;
            if(ans[mid]>q) r=mid;
            else l=mid+1;
        }
        if(l==1e6+1) cout<<"-1 ";
        else cout<<l<<' ';
    }
    return 0;
}