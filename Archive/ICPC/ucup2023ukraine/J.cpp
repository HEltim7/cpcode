#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];
bool mark[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];

    int cycles=0,cnt_eq=0,cnt_same_par=0;
    for(int i=1;i<=n;i++) {
        int idx=i;
        cnt_eq+=arr[i]==i;
        cnt_same_par+=(arr[i]+i)%2==0;
        cycles+=!mark[idx];
        while(!mark[idx]) {
            mark[idx]=1;
            idx=arr[idx];
        }
    }
    bool par=(n-cycles)&1;

    while(q--) {
        int l,r;
        cin>>l>>r;
        cnt_eq-=arr[l]==l;
        cnt_eq-=arr[r]==r;
        cnt_same_par-=(arr[l]+l)%2==0;
        cnt_same_par-=(arr[r]+r)%2==0;
        swap(arr[l],arr[r]);
        cnt_eq+=arr[l]==l;
        cnt_eq+=arr[r]==r;
        cnt_same_par+=(arr[l]+l)%2==0;
        cnt_same_par+=(arr[r]+r)%2==0;
        par^=1;

        if(par) cout<<n<<endl;
        else {
            if(cnt_eq==n) cout<<-1<<endl;
            else if(cnt_same_par==n) cout<<n-2<<endl;
            else cout<<n-1<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}