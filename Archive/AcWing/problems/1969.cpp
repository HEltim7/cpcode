#include<iostream>
using namespace std;

#define endl '\n'
const int N=5e4+10,M=1e6+10;
int cow[N],st[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k,ans=-1;
    cow[0]=1e6+1;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>cow[i];
    for(int i=1,j=0;i<=n;i++){
        if(i-j>k) st[cow[j++]]--;
        if(st[cow[i]]>0) ans=max(ans,cow[i]);
        st[cow[i]]++;
    }
    cout<<ans;
    return 0;
}