#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=4e5+10,INF=0x3f3f3f3f;
int arr[N];
int pre[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(i>k) pre[i]=max(pre[i-1],arr[i]);
    }
    int ans=N;
    pre[n+1]=INF;
    for(int i=1;i<=k;i++){
        int l=k+1,r=n+1;
        while(l<r){
            int mid=l+r>>1;
            if(pre[mid]>arr[i]) r=mid;
            else l=mid+1;
        }
        if(l<n+1) ans=min(ans,l-i);
    }   
    cout<<(ans==N?-1:ans);
    return 0;
}