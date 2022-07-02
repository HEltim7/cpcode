#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N*2];
LL pre[N],ans[N];
bool mark[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n,q,x;
    cin>>n>>q>>x;
    for(int i=1;i<=n;i++) cin>>arr[i],arr[i+n]=arr[i];
    for(int i=1;i<=2*n;i++) pre[i]=pre[i-1]+arr[i];
    LL cnt=x/pre[n]*n;
    int loop=-1,preloop=0;
    x%=pre[n];
    if(x==0) {
        for(int i=1;i<=q;i++) cout<<cnt<<endl;
        return;
    }
    deque<int> dq;
    for(int i=1,cur=1;;i++) {
        int l=cur,r=cur+n;
        mark[cur]=1;
        dq.push_back(cur);
        while(l<r) {
            int mid=l+r>>1;
            if(pre[mid]-pre[cur-1]>=x) r=mid;
            else l=mid+1;
        }
        ans[i]=cnt+l-cur+1;
        cur=l%n+1;
        if(mark[cur]) {
            while(dq.front()!=cur) dq.pop_front(),preloop++;
            loop=dq.size();
            break;
        }
    }

    while(q--) {
        LL k;
        cin>>k;
        if(k<=preloop) cout<<ans[k]<<endl;
        else {
            k-=preloop;
            k=(k-1)%loop+1;
            cout<<ans[preloop+k]<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}