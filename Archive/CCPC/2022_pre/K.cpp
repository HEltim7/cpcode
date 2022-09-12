#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

using LL=long long;
using VI=vector<int>;

VI get(LL x) {
    VI res;
    while(x) res.push_back(x%10),x/=10;
    reverse(res.begin(),res.end());
    return res;
}

void output(VI &x) {
    for(auto i:x) cout<<i;
    cout<<endl;
}

VI add(VI x) {
    reverse(x.begin(),x.end());
    VI res;
    int cur=0;
    for(int i=0;i<x.size();i++) {
        cur=cur+x[i]*2;
        res.push_back(cur%10);
        cur/=10;
    }
    if(cur) res.push_back(cur);
    reverse(res.begin(),res.end());
    return res;
}

void solve() {
    LL y,seed;
    int q;
    cin>>y>>q>>seed;
    VI cur=get(y);
    for(;;) {
        output(cur);
        int res;
        cin>>res;
        if(res==2) return;
        if(res==1) assert(0);
        if(res==0) cur=add(cur);
    }
}

int main() {
    solve();
    return 0;
}
