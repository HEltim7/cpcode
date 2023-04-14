#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
LL pre[N],erp[N],lmax[N],rmax[N],ans;
LL num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+num[i];
    set<LL> s;
    for(int i=n;i>1;i--) erp[i]=erp[i+1]+num[i],s.insert(erp[i]);

    for(int i=1;i<=n-1;i++){
        LL p=pre[i];
        if(s.find(p)!=s.end()) ans=max(ans,p);
        s.erase(erp[i+1]);
    }

    cout<<ans;
    return 0;
}