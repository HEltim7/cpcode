#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10;
int a[N],date[N],suf[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=q;i++){
        int op,x;
        cin>>op>>x;
        if(op==1){
            cin>>a[x];
            date[x]=i;
        }
        else suf[i]=x;
    }
    for(int i=max(n,q);i>=0;i--) suf[i]=max(suf[i],suf[i+1]);
    for(int i=1;i<=n;i++) cout<<max(a[i],suf[date[i]])<<' ';
    return 0;
}