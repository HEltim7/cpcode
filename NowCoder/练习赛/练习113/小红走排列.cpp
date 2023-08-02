#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N],pos[N];

void solve() {
    int n;
    LL k;
    cin>>n>>k;
    int bak=k;

    if(n==1) {
        cout<<1<<endl;
        return;
    }

    int l=2,r=n,len=n-1,from,to,idx=1;
    bool dir=1,lastdir;
    arr[1]=1;
    while(k>=len&&k) {
        lastdir=dir;
        k-=len;
        if(dir) {
            from=l,to=r;
            arr[r]=++idx;
            r--;
        }
        else {
            from=r,to=l;
            arr[l]=++idx;
            l++;
        }
        dir^=1;
        len--;
    }
    if(k<len) {
        int t=len-k;
        idx--;
        debug(lastdir,from,to);
        arr[to]=0;
        if(lastdir) {
            for(int i=from;t;i++,t--) arr[i]=++idx;
            for(int i=to;!arr[i];i--) arr[i]=++idx;
        }
        else {
            for(int i=from;t;i--,t--) arr[i]=++idx;
            for(int i=to;!arr[i];i++) arr[i]=++idx;
        }
    }

    set<int> st;
    for(int i=1;i<=n;i++) pos[arr[i]]=i,st.insert(arr[i]);
    assert(st.size()==n);
    for(int i=1;i<n;i++) {
        bak-=abs(pos[i]-pos[i+1]);
    }
    assert(bak==0);
    for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}