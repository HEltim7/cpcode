#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using ULL=unsigned long long;

void solve() {
    ULL n,x;
    cin>>n>>x;
    
    int h=0;
    for(int i=0;i<63;i++) {
        int a=n>>i&1;
        int b=x>>i&1;
        if((a^1)&&(b)) {
            cout<<-1<<endl;
            return;
        }
        else if(a&&!b) h=max(h,i);
    }
    
    if(n==x) {
        cout<<n<<endl;
        return;
    }

    for(int i=h+1;i>=0;i--) {
        int a=n>>i&1;
        int b=x>>i&1;
        if(a&&b) {
            cout<<-1<<endl;
            return;
        }
    }

    ULL m=0;
    for(int i=h+1;i<63;i++) if(n>>i&1) m|=1ULL<<i;
    m+=1ULL<<(h+1);
    cout<<m<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}