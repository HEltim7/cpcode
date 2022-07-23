#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e5+10;
int arr[N];
int LIS[N];
mt19937 gen(random_device{}());

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

int lis(int n,int arr[]) {
    int ans=0;
    memset(LIS, 0, sizeof(int)*(n+1));
    for(int i=1;i<=n;i++){
        int in=arr[i];
        if(in>LIS[ans]||ans==0){
            LIS[++ans]=in;
            continue;
        }

        int l=1,r=ans,mid=1;
        while(l<r){
            mid=l+r>>1;
            if(LIS[mid]==in) break;
            else if(LIS[mid]>in) r=mid;
            else l=mid+1;
        }
        if(LIS[mid]==in) continue;

        if(mid+1<=ans&&LIS[mid]<in&&LIS[mid+1]>in) mid++;
        LIS[mid]=min(LIS[mid],in);
    }
    return ans;
}

int solve(int n) {
    int res=1e9;
    for(int i=1;i<=n;i++) arr[i]=i;
    shuffle(arr+1, arr+1+n,gen);
    // debug(arr,1,n);
    res=min(res,lis(n,arr));
    reverse(arr+1,arr+1+n);
    res=min(res,lis(n,arr));
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t=1000000;
    int ans=1e9;
    for(int i=1;i<=t;i++) ans=min(ans,solve(101));
    cout<<ans<<endl;
    return 0;
}