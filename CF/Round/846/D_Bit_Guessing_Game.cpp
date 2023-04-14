#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;

void solve() {
    auto ask=[](int x) {
        cout<<"- "<<x<<endl;
        int in;
        cin>>in;
        return in;
    };
    auto fin=[](int x) {
        cout<<"! "<<x<<endl;
    };

    int cnt,left,ans=0,pre=1;
    cin>>cnt;
    left=cnt;
    while(cnt) {
        int cur=ask(pre);
        int lwbt=cur-cnt+1;
        pre=1<<lwbt;
        ans+=1<<lwbt;
        cnt--;
    }
    fin(ans);
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}