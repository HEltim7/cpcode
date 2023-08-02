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
constexpr int INF=2e9;

void solve() {
    multiset<int> st,xval;
    st.insert(-1),st.insert(INF);
    int q;
    cin>>q;
    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int cur;
            cin>>cur;
            auto it=st.insert(cur);
            int pre=*prev(it);
            int suf=*next(it);
            if(pre!=-1&&suf!=INF) xval.erase(xval.find(pre^suf));
            if(pre!=-1) xval.insert(pre^cur);
            if(suf!=INF) xval.insert(cur^suf);
        }
        else if(op==2) {
            int cur;
            cin>>cur;
            auto it=st.find(cur);
            int pre=*prev(it);
            int suf=*next(it);
            if(pre!=-1&&suf!=INF) xval.insert(pre^suf);
            if(pre!=-1) xval.erase(xval.find(pre^cur));
            if(suf!=INF) xval.erase(xval.find(cur^suf));
            st.erase(it);
        }
        else cout<<*xval.begin()<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}