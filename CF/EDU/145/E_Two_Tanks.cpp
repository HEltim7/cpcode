#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e4+10,M=1e3+10;
int v[N],ans[M][M];

void solve() {
    int n,A,B;
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++) cin>>v[i],v[i]=-v[i];

    auto work=[&](int cd) {
        int minn=max(0,cd-B);
        int maxx=min(A,cd);

        int l=minn,r=maxx;
        int lcnt=1,rcnt=1,tot=maxx-minn+1;
        for(int i=1;i<=n;i++) {
            if(v[i]>0) {
                int disr=min(maxx-r,v[i]);
                int disl=min(maxx-l,v[i]);
                int last=r-l;
                r+=disr;
                l+=disl;
                int cur=r-l;
                rcnt+=last-cur;
            }
            else {
                int disl=min(l-minn,-v[i]);
                int disr=min(r-minn,-v[i]);
                int last=r-l;
                l-=disl;
                r-=disr;
                int cur=r-l;
                lcnt+=last-cur;
            }
        }
        vector<int> arr;
        for(int i=1;i<=lcnt;i++) arr.push_back(l);
        for(int i=l+1;i<=r-1;i++) arr.push_back(i);
        for(int i=1;i<=rcnt;i++) arr.push_back(r);
        for(int i=minn,idx=0;i<=maxx;i++) ans[i][cd-i]=arr[idx++];
    };

    for(int cd=0;cd<=A+B;cd++) work(cd);
    for(int i=0;i<=A;i++)
        for(int j=0;j<=B;j++)
            cout<<ans[i][j]<<" \n"[j==B];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}