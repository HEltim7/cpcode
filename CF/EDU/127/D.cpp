#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

inline int cal(int pre,int mid,int suf){
    return abs(pre-mid)+abs(mid-suf)-abs(pre-suf);
}

int getmin(int n,int x){
    int res=abs(1-x)+abs(x-arr[1]);
    int minn=abs(1-arr[1]);
    for(int i=1;i<=n;i++){
        int valx=i==n?abs(arr[n]-x):cal(arr[i],x,arr[i+1]);
        int val1=min(minn,cal(arr[i],1,x));
        res=min(res,valx+val1);
        minn=min(minn,cal(arr[i],1,arr[i+1]));
    }
    return res;
}

void solve(){
    int n,x,maxx=0,minn=N;
    LL dif=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) maxx=max(maxx,arr[i]),minn=min(minn,arr[i]);
    for(int i=2;i<=n;i++) dif+=abs(arr[i]-arr[i-1]);

    if(maxx>=x&&minn<=1) cout<<dif<<endl;
    else if(maxx>=x||minn<=1){
        int val=maxx>=x?1:x;
        int ans;
        ans=min(abs(val-arr[1]),abs(val-arr[n]));
        for(int i=1;i<n;i++) ans=min(ans,cal(arr[i],val,arr[i+1]));
        cout<<dif+ans<<endl;
    }
    else{
        int ans=getmin(n,x);
        reverse(arr+1,arr+1+n);
        ans=min(ans,getmin(n,x));
        cout<<dif+ans<<endl;
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