#include <vector>
#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;
using LL=long long;
constexpr int N=1e6+10;
LL arr[N];

void solve() {
    LL n,m,k=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        cnt+=arr[i]/2;
        k++;
        arr[i]--;
    }
    if(cnt<m) {
        cout<<-1<<endl;
        return;
    }
    sort(arr+1,arr+1+n,[](const LL &l,const LL &r){
        if((l&1)==(r&1)) return l>r;
        return (l&1)<(r&1);
    });

    bool flag=1;
    for(int i=1;i<=n&&m;i++) {
        LL t=min(m,arr[i]/2);
        arr[i]-=t*2;
        k+=t*2;
        m-=t;
    }
    if(m) {
        for(int i=n;i>=1&&m;i--) {
            k++;
            m--;
        }
    }
    else k--;

    cout<<k<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}