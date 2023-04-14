#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
bool mark[N];
int slash[N],line[N];
map<pair<int,int>,int> mp;

void init() {
    for(int i=1;i<N;i++) line[i]=slash[i]=1e9;
    int n=1e6;
    mark[0]=1;
    slash[0]=line[0]=1;
    mp[{0,0}]=1;
    for(int i=1,x=0,y=0;x<=n&&y<=n;i++) {
        x+=2,y++;
        while(x<=n&&y<=n&&mark[x]||mark[y]) x++,y++;
        mark[x]=mark[y]=1;
        line[x]=line[y]=i*2+1;
        slash[x-y]=i*2+1;
        mp[{x,y}]=i*2;
    }
}

void solve() {
    int x,y;
    cin>>x>>y;
    if(x<y) swap(x,y);
    int c=0;
    if(mp.count({x,y})) c=mp[{x,y}];
    else c=min({line[x],line[y],slash[x-y]});
    cout<<int(2e9)-c<<endl;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}