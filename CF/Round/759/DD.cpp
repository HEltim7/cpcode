#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e5+10;
int arr[N],ans;

void merge_sort(int l,int r,int num[]){
    if(l>=r) return;
    int mid=l+r>>1;
    int tmp[N],cnt=l,i=l,j=mid+1;
    merge_sort(l,mid,num),merge_sort(mid+1,r,num);
    while(i<=mid&&j<=r){
        if(num[i]>num[j]){
            ans+=mid-i+1;
            tmp[cnt++]=num[j++];
        }
        else tmp[cnt++]=num[i++];
    }
    while(i<=mid) tmp[cnt++]=num[i++];
    while(j<=r) tmp[cnt++]=num[j++];
    for(int i=l;i<=r;i++) num[i]=tmp[i];
}

void solve() {
    int n;
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    merge_sort(1,n,arr);
    if(ans&1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}