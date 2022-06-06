#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,M=20;
int arr[N],cnt[N];

int cal(int x) {
    int t=1;
    while(t<x) t*=2;
    return t-x;
}

int qpow(int a,int b){
    if(b==-1) return 0;
    int res=1;
    while(b){
        if(b&1) res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

void solve() {
    int n,ans=1e8;
    cin>>n;
    memset(cnt,0,sizeof (int)*(n+1));
    for(int i=1;i<=n;i++) cin>>arr[i],cnt[arr[i]]++;
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=0;i<=n;i++) {
        if(i&&cnt[i]==cnt[i-1]) continue;
        int res=cal(cnt[i]);

        for(int j=0;j<M;j++) 
            for(int k=0;k<M;k++) {
                int pre=qpow(2,j-1);
                int suf=qpow(2,k-1);
                if(pre+suf>cnt[n]-cnt[i]) break;
                pre=qpow(2,j),suf=qpow(2,k);
                if(pre+suf<cnt[n]-cnt[i]) continue;

                int l=i+1,r=n;
                while(l<r) {
                    int mid=l+r>>1;
                    int middle=cnt[mid]-cnt[i];
                    int heavy=cnt[n]-cnt[mid];
                    if(middle<=pre&&middle*2>=pre&&heavy<=suf&&heavy*2>=suf)
                        ans=min(ans,res+pre+suf-(cnt[n]-cnt[i]));
                    else if()
                }
            }
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