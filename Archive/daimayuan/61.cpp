#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
LL num[N],n,k;

inline bool check(LL x){
    LL res=0;
    for(int i=1;i<=n;i++)
        res+=max(0LL,x-num[i]);
    return res<=k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    LL l=1,r=k+1e8;
    while(l<r){
        auto mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}