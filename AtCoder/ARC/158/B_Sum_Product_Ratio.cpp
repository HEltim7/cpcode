#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=2e5+10;

void solve() {
    vector<int> pos,neg;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in>0) pos.emplace_back(in);
        else neg.emplace_back(in);
    }

    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());

    vector<LD> res;

    auto cal=[&](LL x,LL y,LL z) {
        res.push_back(LD(x+y+z)/(x*y*z));
    };

    auto get=[&](vector<int> &v,int cnt) {
        vector<vector<int>> res;
        if(v.size()<cnt) return res;
        int sz=v.size();
        for(int i=0;i<=cnt;i++) {
            res.push_back({});
            auto &cur=res.back();
            for(int j=0;j<i;j++) cur.push_back(v[j]);
            for(int j=sz-1;j>=sz-(cnt-i);j--) cur.push_back(v[j]);
        }
        return res;
    };

    for(int i=0;i<=3;i++) {
        auto vp=get(pos,i);
        auto vn=get(neg,3-i);
        for(auto x:vp) {
            for(auto y:vn) {
                auto t=x;
                for(auto z:y) t.push_back(z);
                cal(t[0],t[1],t[2]);
            }
        }
    }

    sort(res.begin(),res.end());
    cout<<fixed<<setprecision(15);
    cout<<res.front()<<endl<<res.back()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}