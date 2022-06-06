#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
LL a[N];
int n,k;

inline bool check(LL m){
    LL sum=0;
    int day=1;
    for(int i=1;i<=n;i++){
        if(a[i]*a[i]>m) return 0;
        if(sum+a[i]*a[i]>m) sum=a[i]*a[i],day++;
        else sum+=a[i]*a[i];
    }
    return day<=k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i]*a[i];
    if(k==1){
        cout<<sum<<endl;
        return 0;
    }
    LL l=1,r=sum;
    while(l<r){
        LL mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}