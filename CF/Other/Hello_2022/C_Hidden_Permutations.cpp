#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<cstring>
using namespace std;
const int N=1e4+10;
int ans[N],cnt,n;

int query(int x) {
    assert(++cnt<=2*n);
    int res;
    cout<<"? "<<x<<endl;
    cin>>res;
    return res;
}

void solve() {
    cin>>n;
    memset(ans,0,sizeof (int)*(n+1));
    cnt=0;
    for(int i=1;i<=n;i++) {
        if(ans[i]) continue;
        for(int pre=query(i),cur;!ans[pre];pre=cur) {
            cur=query(i);
            ans[pre]=cur;
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}