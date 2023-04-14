#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int grid[N][N];

void solve() {
    int n,m,niux,niuy,cnt=0;
    cin>>n>>m;
    set<int> st;
    for(int i=1;i<=n*n;i++) st.insert(i);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) grid[i][j]=0;
    for(int i=1;i<=m;i++) {
        int op,x,y,z;
        cin>>op;
        if(op==1) {
            cin>>x>>y>>z;
            st.erase(z);
            grid[x][y]=z;
        }
        else {
            cin>>niux>>niuy;
            cnt++;
        }
    }

    auto output=[&](bool x) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cout<<(x?grid[i][j]:0)<<" \n"[j==n];
    };

    auto fill=[&]() {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(!grid[i][j])
                    grid[i][j]=*st.begin(),st.erase(st.begin());
        output(1);
    };

#define fin() { output(0); return; }

    if(cnt>=2) output(0);
    else if(cnt==0) fill();
    else {
        int &niu=grid[niux][niuy];
        int maxx=0,minn=n*n;
        for(int i=1;i<=n;i++) {
            if(i==niuy) continue;
            if(!grid[niux][i]) {
                int cur=*st.begin();
                if(niu&&cur>niu) fin();
                st.erase(st.begin());
                grid[niux][i]=cur;
            }
            else maxx=max(maxx,grid[niux][i]);
        }

        if(!niu) {
            auto it=st.upper_bound(maxx);
            if(it==st.end()) fin();
            niu=*it;
            st.erase(it);
        }
        else if(maxx>niu) fin();

        for(int i=1;i<=n;i++) {
            if(!grid[i][niuy]) {
                int cur=*st.rbegin();
                if(cur<niu) fin();
                st.erase(prev(st.end()));
                grid[i][niuy]=cur;
            }
            else minn=min(minn,grid[i][niuy]);
        }
        if(minn<niu) fin();

        fill();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}