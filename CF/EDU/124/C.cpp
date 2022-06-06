#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
int a[N],b[N];

inline LL get(int x,set<int> &st){
    int res=0;
    auto it=st.lower_bound(x);
    if(it==st.end()) return abs(x-*prev(it));
    else if(it==st.begin()) return abs(x-*it);
    return min(abs(x-*it),abs(x-*prev(it)));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> st[2];
        for(int i=1;i<=n;i++) cin>>a[i],st[0].insert(a[i]);
        for(int i=1;i<=n;i++) cin>>b[i],st[1].insert(b[i]);

        LL up1dn1,up1dn2,up2dn1,up2dn2;
        up1dn1=abs(a[1]-b[1]);
        up1dn2=abs(a[1]-b[n]);
        up2dn1=abs(a[n]-b[1]);
        up2dn2=abs(a[n]-b[n]);

        LL up1,up2,dn1,dn2;
        up1=get(a[1],st[1]);
        up2=get(a[n],st[1]);
        dn1=get(b[1],st[0]);
        dn2=get(b[n],st[0]);

        LL ans=1e12;
        ans=min(ans,up1dn1+up2dn2);
        ans=min(ans,up1dn2+up2dn1);
        ans=min(ans,up1dn1+up2+dn2);
        ans=min(ans,up1dn2+up2+dn1);
        ans=min(ans,up2dn1+up1+dn2);
        ans=min(ans,up2dn2+up1+dn1);
        ans=min(ans,up1+up2+dn1+dn2);

        cout<<ans<<endl;
    }
    return 0;
}