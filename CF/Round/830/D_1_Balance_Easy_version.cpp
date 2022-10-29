#include <map>
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
using PLI=pair<LL,int>;
constexpr int N=2e5+10;
set<LL> st;
map<LL,LL> last;
LL ans[N];

void solve() {
    int q;
    cin>>q;
    for(int i=1;i<=q;i++) {
        char op;
        LL x;
        cin>>op>>x;
        if(op=='+') st.insert(x);
        else {
            LL val=0;
            if(last.find(x)!=last.end()) val=last[x];
            // debug(x,val);
            for(;;) {
                auto it=st.find(val+x);
                if(it!=st.end()) val=*it;
                else break;
            }
            last[x]=val;
            cout<<val+x<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}