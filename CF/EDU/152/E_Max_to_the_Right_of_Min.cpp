#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
int arr[N];

template<int size,typename T=int> struct SparseTable {
    using F=function<T(T,T)>;
    constexpr static int M=__lg(size)+1;
    T st[M][size];
    F merge;

    void build(int n) {
        for(int i=1;i<=n;i++) st[0][i]=arr[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=merge(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return merge(st[k][l],st[k][r-(1<<k)+1]);
    }

    SparseTable(F merge): merge(merge) {}
};

SparseTable<N> stmx([](int x,int y) { return max(x,y); });
SparseTable<N> stmn([](int x,int y) { return min(x,y); });

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    stmx.build(n);
    stmn.build(n);

    auto find_right=[&](auto l,auto r,auto check) {
        while(l<r) {
            auto mid=(l+r+1)/2;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        return l;
    };

    auto find_left=[&](auto l,auto r,auto check) {
        while(l<r) {
            auto mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    };

    LL ans=0;
    for(int i=1;i<=n;i++) {
        int lmx=find_left(1, i, [&](int mid) { return stmx.query(mid, i)==arr[i]; });
        int rmx=find_right(i, n, [&](int mid) { return stmx.query(i, mid)==arr[i]; });
        if(i-lmx<=rmx-i) {
            for(int j=i-1,minn=arr[i-1];j>=lmx;j--) {
                minn=min(minn,arr[j]);
                int r=find_right(i, rmx, [&](int mid) { return stmn.query(i, mid)>minn; });
                ans+=r-i+1;
            }
        }
        else {
            for(int j=i,minn=arr[i];j<=rmx;j++) {
                minn=min(minn,arr[j]);
                int l=find_right(lmx-1, i, [&](int mid) { return stmn.query(mid, i)<minn; });
                ans+=l-lmx+1;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}