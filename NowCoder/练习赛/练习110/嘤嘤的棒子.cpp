#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=30;
int cnt[N+10][N+10],suf[N+10],ans,k;

vector<int> pre;
void dfs(int deep,int idx,int res) {
    if(deep==k) {
        ans=min(ans,res);
        return;
    }

    int tot=0;
    for(int i=idx;i<=(N-(k-deep))&&ans;i++) {
        int t=res;
        for(int x:pre) t-=cnt[i][x];
        t-=suf[i];
        dfs(deep+1,i+1,t);
        pre.push_back(i),tot++;
    }

    while(tot--) pre.pop_back();
}

void solve() {
    int n;
    cin>>n>>k;
    k=min(k,N);
    string s;
    cin>>s;

    vector<int> arr;
    arr.reserve(n);
    for(auto x:s) {
        if(x>='a'&&x<='z') arr.push_back(x-'a');
        else if(x==',') arr.push_back(26);
        else if(x=='.') arr.push_back(27);
        else if(x=='!') arr.push_back(28);
        else if(x=='?') arr.push_back(29);
    }

    for(int i=0,j=n-1;i<j;i++,j--) {
        int x=arr[i],y=arr[j];
        if(x!=y) cnt[x][y]++,cnt[y][x]++,ans++;
    }
    debug(ans);

    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            suf[i]+=cnt[i][j];
        }
    }
    dfs(0,0,ans);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}