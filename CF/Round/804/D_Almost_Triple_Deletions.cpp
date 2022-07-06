#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e3+10;
int arr[N];
bool mark[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    memset(mark,0,sizeof (bool)*(n+1));
    vector<pair<int,int>> seg;
    int ans=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        mark[arr[i]]=1;
        if(seg.size()&&seg.back().first==arr[i]) seg.back().second++;
        else seg.emplace_back(arr[i],1);
    }
    debug(seg);
    for(int v=1;v<=n;v++) {
        int cnt=0;
        if(!mark[v]) continue;
        debug(v);
        auto cur=seg;
        while(cur.size()) {
            if(cur.back().first==v) {
                cnt+=cur.back().second;
                cur.pop_back();
            }
            else {
                auto [val,num]=cur.back();
                cur.pop_back();
                while(num>0) {
                    if(cur.empty()) {
                        int t=min(num,cnt);
                        cnt-=t;
                        num-=t;
                        break;
                    }
                    if(cur.back().first==val) {
                        num+=cur.back().second;
                        cur.pop_back();
                        continue;
                    }
                    int t=min(num,cur.back().second);
                    num-=t;
                    cur.back().second-=t;
                    if(cur.back().second==0) cur.pop_back();
                } 
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}