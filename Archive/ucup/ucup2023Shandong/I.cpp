#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
int arr[N],heap[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>heap[i];

    auto jump=[&](int pos,int val,bool type) {
        if(heap[pos]!=val) {
            if(!type&&heap[pos]<val||
                type&&heap[pos]>val) return -1;
        }
        while(heap[pos]!=val&&pos>1) {
            if(!type&&heap[pos/2]<val||
                type&&heap[pos/2]>val) return -1;
            pos/=2;
        }
        if(heap[pos]!=val) return -1;
        if(pos>1&&(!type&&heap[pos/2]>val||
                    type&&heap[pos/2]<val)) return -1;
        return pos;
    };

    auto erase=[&](int from,int to) {
        vector<int> path;
        do {
            path.push_back(from);
            from/=2;
        }while (to<=from);

        reverse(path.begin(),path.end());
        for(int i=1;i<path.size();i++) {
            int up=path[i-1];
            int dn=path[i];
            heap[up]=heap[dn];
        }
    };

    string ans;
    for(int i=n;i>=1;i--) {
        int minp=jump(i, arr[i], 0);
        int maxp=jump(i, arr[i], 1);
        if(minp==-1&&maxp==-1) {
            cout<<"Impossible"<<endl;
            return;
        }
        ans.push_back(minp!=-1?'0':'1');
        erase(i, minp!=-1?minp:maxp);
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}