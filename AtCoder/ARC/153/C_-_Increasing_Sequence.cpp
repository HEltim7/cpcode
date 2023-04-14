#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],suf[N];
LL ans[N];

void solve() {
    int n,idxP=0,idxN=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=n;i>=1;i--) {
        suf[i]=suf[i+1]+arr[i];
        if(arr[i]==1) cnt++; else cnt--;
        if(suf[i]==1) idxP=i;
        if(suf[i]==-1) idxN=i;
    }

    LL sum=0;
    int idx=0;
    for(int i=1;i<=n;i++) ans[i]=i,sum+=arr[i]*ans[i];
    if(cnt==0&&((sum>0&&!idxN)||(sum<0&&!idxP))) cout<<"No"<<endl;
    else {
        cout<<"Yes"<<endl;
        if((sum>0&&!idxN)||(sum<0&&!idxP)) {
            LL t=(abs(sum)+abs(cnt)-1)/abs(cnt);
            if(sum*cnt>=0) for(int i=1;i<=n;i++) ans[i]-=t;
            else for(int i=1;i<=n;i++) ans[i]+=t;
        }

        sum=0;
        for(int i=1;i<=n;i++) sum+=arr[i]*ans[i];
        if(sum) for(int i=sum>0?idxN:idxP;i<=n;i++) ans[i]+=abs(sum);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}