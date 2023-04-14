#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL arr[N];

void solve() {
    LL n,k,b,s;
    cin>>n>>k>>b>>s;
    LL low=k*b;
    LL upp=low+(k-1)*n;
    if(s<low||s>upp) cout<<-1<<endl;
    else {
        LL left=s-low;
        for(int i=1;i<=n;i++) arr[i]=0;
        for(int i=1;i<=n&&b;i++) arr[i]=k,b--;
        arr[1]+=b*k;
        for(int i=1;i<=n&&left;i++) {
            LL t=min(left,k-1);
            arr[i]+=t;
            left-=t;
        }
        for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
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