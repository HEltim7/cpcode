#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL arr[N],pre[N];

void solve() {
    int n,k;
    LL x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i]-=x;
    }
    x*=2;
    debug(arr,1,n);

    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
    LL ans=0;

    if(x>=0) {
        for(int len=1;len<k;len++) {
            LL cur=x*len;
            for(int i=0,j=len;j<=n;i++,j++) {
                ans=max(ans,pre[j]-pre[i]+cur);
            }
        }

        set<LL> st;
        LL cur=x*k;
        for(int i=k;i<=n;i++) {
            st.insert(pre[i-k]);
            debug(i,i-k);
            ans=max(ans,pre[i]-*st.begin()+cur);
        }
        cout<<ans<<endl;
    }
    else {
        for(int len=n;len>n-k;len--) {
            LL cur=(k-(n-len))*x;
            for(int i=0,j=len;j<=n;i++,j++) {
                ans=max(ans,pre[j]-pre[i]+cur);
            }
        }
        debug(ans);

        multiset<LL> st;
        st.insert(pre[0]);
        if(n>k) {
            for(int i=1;i<=n;i++) {
                if(i>n-k) st.erase(st.find(pre[i-(n-k+1)]));
                ans=max(ans,pre[i]-*st.begin());
                st.insert(pre[i]);
            }
        }
        cout<<ans<<endl;
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