#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL x,y,k,n,T,sum=0;
    cin>>x>>y>>k>>n>>T;
    LL bx=x;
    for(int i=1;i<=n;i++) {
        LL cur=n-i+1;
        sum+=cur;
        T-=x*cur;
        if(T<=0) {
            cout<<i;
            return;
        }
        x=bx+(sum/k)*y;
    }
    cout<<-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}