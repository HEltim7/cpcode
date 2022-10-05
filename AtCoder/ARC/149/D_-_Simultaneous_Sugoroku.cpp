#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;

int link[N],ans[N],X[N];
int mark[N];

void find_ans(int x) {
    if(ans[x]) return;
    find_ans(link[x]);
    mark[x]=mark[link[x]];
    ans[x]=ans[link[x]]*mark[x];
}

void solve() {
    int n,m,L=1e6,R=1,axis=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>X[i],L=min(L,X[i]),R=max(R,X[i]);
    for(int i=1;i<=n;i++) {
        int d,cur;
        cin>>d;
        if(axis<L) cur=axis+d;
        else cur=axis-d;
        if(cur>=L&&cur<=R) {
            ans[cur]=i;
            mark[cur]=1;
            if(cur-L<=R-cur) while(L<=cur) link[L]=cur+(cur-L),L++;
            else while(R>=cur) link[R]=cur-(R-cur),R--;
        }
        axis=cur;
    }

    for(int i=L;i<=R;i++) ans[i]=i-axis,mark[i]=-1;
    for(int i=1;i<=n;i++) find_ans(X[i]);
    for(int i=1;i<=n;i++) cout<<(mark[X[i]]==1?"Yes ":"No ")<<ans[X[i]]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}