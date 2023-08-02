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
constexpr int N=310;
int arr[N][N],pre[N][N];

template<int size,typename T=int> struct SparseTable {
    constexpr static int M=__lg(size);
    T arr[size],st[M][size];

    void build(int n) {
        for(int i=1;i<=n;i++) st[0][i]=arr[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=min(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        // if(r<l) return 0;
        int k=__lg(r-l+1);
        return min(st[k][l],st[k][r-(1<<k)+1]);
    }
};
SparseTable<N> st[N];

int get(int r,int c,int x,int y) {
    return pre[x][y]-pre[x][c-1]-pre[r-1][y]+pre[r-1][c-1];
}

LL ans=0;
int n,m;

void solve(const int L,const int R) {
    int mid=(L+R)/2;
    if(L!=R) solve(L,mid),solve(mid+1,R);
    debug(L,R);
    for(int i=1;i<=m;i++) {
        for(int j=i;j<=m;j++) {
            int l=mid+1,r=mid;
            int minn=N;

            for(;l>L||r<R;) {
                int lmin=st[l-1].query(i, j);
                int rmin=st[r+1].query(i, j);
                if(l==L) minn=min(minn,rmin),r++;
                else if(r==R) minn=min(minn,lmin),l--;
                else if(lmin>=rmin) minn=min(minn,lmin),l--;
                else minn=min(minn,rmin),r++;

                while(l>L&&st[l-1].query(i, j)>=minn) l--;
                while(r<R&&st[r+1].query(i, j)>=minn) r++;
                ans=max(ans,1LL*get(l,i,r,j)*minn);
            }
        }
    }
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
            ans=max(ans,1LL*arr[i][j]*arr[i][j]);
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+arr[i][j];
            st[i].arr[j]=arr[i][j];
        }
        st[i].build(m);
    }

    solve(1,n);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}