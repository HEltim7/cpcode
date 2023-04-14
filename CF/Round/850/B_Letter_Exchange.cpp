#include <map>
#include <tuple>
#include <vector>
#include <cassert>
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
constexpr int N=1e5+10;
const string win="inw";

void solve() {
    int n;
    cin>>n;
    map<string,vector<int>> mp;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        if(s!=win) mp[s].emplace_back(i);
    }

    auto lack=[](const string &s,char c) {
        for(auto x:s) if(x==c) return false;
        return true;
    };

    auto more=[](const string &s,char c) {
        int cnt=0;
        for(auto x:s) if(x==c) cnt++;
        return cnt>1;
    };

    auto exchange=[](string &s,char x,char y) {
        for(auto &z:s) 
            if(z==x) {
                z=y;
                break;
            }
        sort(s.begin(),s.end());
    };

    vector<tuple<int,char,int,char>> res;

    auto fn1=[&]() {
        for(auto it=mp.begin();it!=mp.end();it++) {
            for(auto jt=next(it);jt!=mp.end();jt++) {
                auto &[s,v1]=*it;
                auto &[t,v2]=*jt;
                for(auto x:win) {
                    for(auto y:win) {
                        if(lack(s,x)&&more(s,y)&&lack(t,y)&&more(t,x)) {
                            string ss=s,tt=t;
                            exchange(ss, y, x);
                            exchange(tt, x, y);
                            auto v1t=v1.begin(),v2t=v2.begin();
                            for(;v1t!=v1.end()&&v2t!=v2.end();v1t++,v2t++) {
                                res.emplace_back(*v1t,y,*v2t,x);
                                if(ss!=win) mp[ss].emplace_back(*v1t);
                                if(tt!=win) mp[tt].emplace_back(*v2t);
                            }
                            v1.erase(v1.begin(),v1t);
                            v2.erase(v2.begin(),v2t);
                            for(auto i=mp.begin();i!=mp.end();) 
                                if(i->second.empty()) i=mp.erase(i);
                                else i++;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    };

    auto fn2=[&]() {
        for(auto it=mp.begin();it!=mp.end();it++) {
            for(auto jt=next(it);jt!=mp.end();jt++) {
                auto &[s,v1]=*it;
                auto &[t,v2]=*jt;
                for(auto x:win) {
                    for(auto y:win) {
                        if(lack(s,x)&&more(s,y)&&more(t,x)) {
                            string ss=s,tt=t;
                            exchange(ss, y, x);
                            exchange(tt, x, y);
                            auto v1t=v1.begin(),v2t=v2.begin();
                            for(;v1t!=v1.end()&&v2t!=v2.end();v1t++,v2t++) {
                                res.emplace_back(*v1t,y,*v2t,x);
                                if(ss!=win) mp[ss].emplace_back(*v1t);
                                if(tt!=win) mp[tt].emplace_back(*v2t);
                            }
                            v1.erase(v1.begin(),v1t);
                            v2.erase(v2.begin(),v2t);
                            for(auto i=mp.begin();i!=mp.end();) 
                                if(i->second.empty()) i=mp.erase(i);
                                else i++;
                            return;
                        }
                    }
                }
            }
        }
    };

    while(mp.size()) {
        // debug(mp);
        if(!fn1()) fn2();
    }

    cout<<res.size()<<endl;
    for(auto [a,b,c,d]:res) cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}