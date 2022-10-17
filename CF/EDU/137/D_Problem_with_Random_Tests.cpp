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

void solve() {
    int n;
    string s,res,bak;
    cin>>n>>s;
    s=" "+s;
    bak=s;

    vector<int> cod;
    int idx=1;
    while(idx<=n&&s[idx]=='0') idx++;
    if(idx>n) {
        cout<<"0"<<endl;
        return;
    }
    for(int i=idx;i<=n;i++) res.push_back(s[i]);
    while(idx<=n&&s[idx]=='1') cod.push_back(idx),idx++;
    if(idx>n) {
        cout<<res<<endl;
        return;
    }

    for(int i=idx;i<=n&&cod.size();i++) {
        if(s[i]=='0') {
            vector<int> good,bad;
            for(auto x:cod) 
                if(s[x]=='1') good.push_back(x+1);
                else bad.push_back(x+1);
            if(good.size()) {
                bak[i]='1';
                cod.clear();
                for(auto x:good) if(x<=n) cod.push_back(x);
            }
            else {
                cod.clear();
                for(auto x:bad) if(x<=n) cod.push_back(x);
            }
        }
        else {
            for(auto &x:cod) x++;
            if(cod.back()>n) cod.pop_back();
        }

        debug(i,cod,bak);
    }

    idx=1;
    while(idx<=n&&bak[idx]=='0') idx++;
    for(int i=idx;i<=n;i++) cout<<bak[i];
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}