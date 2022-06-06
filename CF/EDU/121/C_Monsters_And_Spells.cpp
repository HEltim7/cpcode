#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int k[N];
int h[N];
int lim[N];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

LL cal(LL a,LL b){
    return (a+b)*(b-a+1)/2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        LL res=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>k[i];
        for(int i=1;i<=n;i++) cin>>h[i];
        for(int i=1;i<=n;i++) lim[i]=k[i]-h[i];
        for(int i=n-1;i>=1;i--) lim[i]=min(lim[i+1],lim[i]);
        debug(lim,1,n);
        for(int i=1,pre=0;i<=n;i++) {
            if(k[i]-k[i-1]>=h[i]&&k[i-1]<=lim[i]) {
                pre=k[i]-lim[i];
                res+=cal(1,pre);
                debug(1,pre,res);
            }
            else{
                res+=cal(pre+1,pre+k[i]-k[i-1]);
                pre+=k[i]-k[i-1];
                debug(2,pre,res);
            }
            // debug(pre);
        }
        cout<<res<<endl;
    }
    return 0;
}