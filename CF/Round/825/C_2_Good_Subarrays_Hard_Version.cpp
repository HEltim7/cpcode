#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using VI=vector<int>;
constexpr int N=2e5+10;
int arr[N],max1[N],max2[N],L[N],R[N],r1[N],r2[N];
LL pre1[N],pre2[N];

void init(int n,int maxx[],LL pre[],int res[]) {
    for(int i=1,r=1;i<=n;i++) {
        while(r<n&&maxx[r+1]<=i) r++;
        res[i]=r;
        pre[i]=pre[i-1]+r-i+1;
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i]=i-arr[i]+1;
        max1[i]=max1[i-1];
        max2[i]=max2[i-1];
        if(arr[i]>=max1[i]) {
            max2[i]=max1[i];
            max1[i]=arr[i];
        }
        else if(arr[i]>max2[i]) max2[i]=arr[i];
    }

    init(n, max1, pre1, r1);
    init(n, max2, pre2, r2);
    LL ans=pre1[n];
    for(int i=1;i<=n;i++)
        if(L[r1[i]]==0) L[r1[i]]=R[r1[i]]=i;
        else R[r1[i]]=i;
    for(int i=n;i>=1;i--)
        if(L[i]==0) L[i]=L[i+1];
    
    int m;
    cin>>m;
    while(m--) {
        int p,x;
        cin>>p>>x;

        if(p-x+1>=arr[p]) {
            int l=L[p];
            int r=p-x;
            LL cnt=r-l+1,val=p-l;
            if(r<l) cout<<ans<<endl;
            else cout<<ans-((pre1[r]-pre1[l-1])-(val+val-cnt+1)*cnt/2)<<endl;
        }
        else {
            int l=max(L[p-1],p-x+1);
            int r=R[p-1];
            if(r==0) cout<<ans<<endl;
            else cout<<ans+(pre2[r]-pre2[l-1])-(pre1[r]-pre1[l-1])<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}