#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) __lg((x&(-x)))
using LL=long long;

void solve() {
    LL a,b,d;
    cin>>a>>b>>d;
    LL t=a|b,res=0;
    if(lowbit(t)<lowbit(d)) {
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<60;i++) {
        if((t>>i&1)&&!(res>>i&1)) {
            res+=d<<(i-lowbit(d));
        }
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}