#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=50;
int arr[N],pos[N];
bool mark[N];

void fn(int l,int r) {
    if(l+1==r) swap(arr[l],arr[r]);
    else fn(l,r-1),fn(l+1,r);
}

int dfs(int u) {
    if(mark[u]) return 0;
    mark[u]=1;
    int res=1;
    res+=dfs(pos[u]);
    return res;
}

void solve() {
    for(int z=2;z<=32;z++) {
        int n=z;
        for(int i=1;i<=n;i++) arr[i]=i;
        fn(1,n);
        for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
        cout<<endl;

        for(int i=1;i<=n;i++) pos[arr[i]]=i,mark[i]=0;
        for(int i=1;i<=n;i++) if(!mark[i]) {
            int t=dfs(i);
            if(t==1) cout<<'-'<<' ';
            else cout<<t<<' ';
        }
        cout<<endl;
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}