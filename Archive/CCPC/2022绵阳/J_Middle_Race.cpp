#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
LL a[5],ans[5];

void solve() {
    int n;
    cin>>n>>a[1]>>a[2]>>a[3];
    LL sum=(a[1]+a[2]+a[3])*n;
    sort(a+1,a+4,greater<>());
    
    LL minn=1e12;
    for(int i=0;i<=n;i++) {
        LL cnt=a[1]*i+a[3]*(n-i);
        if(cnt*3>sum) break;
        int l=0,r=n-i;
        LL val=a[2]-a[3];
        while(l<r) {
            int mid=(l+r+1)/2;
            if((cnt+mid*val)*3<=sum) l=mid;
            else r=mid-1;
        }
        
        LL res=sum-(cnt+l*val)*3;
        if(res<=minn) {
            minn=res;
            ans[1]=i,ans[2]=l,ans[3]=n-i-l;
        }
    }

    for(int i=n;i>=0;i--) {
        LL cnt=a[1]*i+a[2]*(n-i);
        if(cnt*3<sum) break;
        int l=0,r=n-i;
        LL val=a[3]-a[2];
        while(l<r) {
            int mid=(l+r+1)/2;
            if((cnt+mid*val)*3>=sum) l=mid;
            else r=mid-1;
        }

        LL res=(cnt+l*val)*3-sum;
        if(res<=minn) {
            minn=res;
            ans[1]=i,ans[3]=l,ans[2]=n-i-l;
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=3;j++)
            if(ans[j]) {
                ans[j]--;
                cout<<a[j]<<endl;
                break;
            }
        int x,y;
        cin>>x>>y;
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}