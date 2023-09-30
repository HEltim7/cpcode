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

template<int size,typename T> struct SparseTable2D {
    T st[2][size][size];
    
    T merge(T a,T b,T c,T d) {
        return max({a,b,c,d});
    }

    void build(int n,int m,int b) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                st[0][i][j]=lcm(i, j);

        for(int k=1,t=1<<k;k<=b;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                for(int x=1,y=x+t-1,z=x+t/2;y<=m;x++,y++,z++)
                    st[k&1][i][x]=merge(st[(k-1)&1][i][x],st[(k-1)&1][mid][x],st[(k-1)&1][i][z],st[(k-1)&1][mid][z]);
    }

    T query(int x,int y,int len) {
        int k=__lg(len);
        int p=x+len-1-(1<<k)+1;
        int q=y+len-1-(1<<k)+1;
        return merge(st[k&1][x][y],st[k&1][x][q],st[k&1][p][y],st[k&1][p][q]);
    }
};
SparseTable2D<int(5e3+10), int> st;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    st.build(n, m, __lg(k));
    LL sum=0;
    for(int r=1;r+k-1<=n;r++)
        for(int c=1;c+k-1<=m;c++)
            sum+=st.query(r, c, k);
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}