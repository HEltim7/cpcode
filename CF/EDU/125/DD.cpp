#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10;
const LL INF=1e18;
map<LL,int> mp,ans;

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
    for(auto [c,dh]:tmp){
        for(int i=1;i<=C/c&&dh<=INF/i;i++){
            auto it=mp.find(dh*i);
            if(it==mp.end()) mp.insert({dh*i,c*i});
            else if(it->second>c*i) it->second=c*i;
        }
    }
    tmp.clear();
    int pre=1e9;
    ans.insert({-1,-1}),mp.insert({-1,-1});
    for(auto it=prev(mp.end());it!=mp.begin();it=prev(it)){
        auto [dh,c]=*it;
        pre=min(pre,c);
        ans.insert({dh,pre});
    }
    mp.clear();
    ans.insert({INF+1,-1});
    cin>>m;
    while(m--){
        LL d,h;
        cin>>d>>h;
        LL q=d*h;
        auto it=ans.upper_bound(q);
        cout<<it->second<<" ";
    }
    return 0;
}