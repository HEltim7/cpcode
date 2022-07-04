#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,mod=998244353;
int a[N],b[N];
bool mark[N];

void solve() {
    int n,s;
    LL ans=1;
    cin>>n>>s;
    vector<int> A,B;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) if(b[i]!=-1&&a[i]-b[i]>s) ans=0;
    for(int i=1;i<=n;i++) if(b[i]!=-1) mark[b[i]]=1;
    for(int i=1;i<=n;i++) if(!mark[i]) B.push_back(i); else mark[i]=0;
    for(int i=1;i<=n;i++) if(b[i]!=-1) mark[a[i]]=1;
    for(int i=1;i<=n;i++) if(!mark[i]) A.push_back(i); else mark[i]=0;
    int len=A.size();
    for(int i=len-1,j=len;i>=0&&j>=0;i--) {
        while(j&&A[i]-B[j-1]<=s) j--;
        if(i-j+1<0) break;
        ans=ans*(i-j+1)%mod;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}