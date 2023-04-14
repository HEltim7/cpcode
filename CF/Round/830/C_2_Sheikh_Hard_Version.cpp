#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL arr[N],pre[N],xsum[N];
int le[N],re[N];

void solve() {
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
    for(int i=1;i<=n;i++) xsum[i]=xsum[i-1]^arr[i];
    for(int i=n,last=n+1;i>=1;i--) re[i]=last,last=arr[i]?i:last;
    for(int i=1,last=0;i<=n;i++) le[i]=last,last=arr[i]?i:last;

    while(q--) {
        int L,R;
        cin>>L>>R;
        LL res=pre[R]-pre[L-1]-(xsum[R]^xsum[L-1]);

        if(!res) {
            cout<<L<<' '<<L<<endl;
            continue;
        }

        if(!arr[L]) L=re[L];
        if(!arr[R]) R=le[R];
        int l=L,r=R,len=r-l+1;

        for(int k=31;k;k--) {
            int i=L,j=R;
            for(int z=1;z<=k&&le[j]>=i;z++) j=le[j];
            for(;j<=R;i=re[i],j=re[j]) {
                if(pre[j]-pre[i-1]-(xsum[j]^xsum[i-1])==res) {
                    int cur=j-i+1;
                    if(cur<len) {
                        len=cur;
                        l=i,r=j;
                    }
                }
            }
        }
        cout<<l<<' '<<r<<endl;
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