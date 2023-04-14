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
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    auto guess=[&](char zero) {
        string s=a,t=b;
        while(s.size()>1&&s.back()==zero) s.pop_back();
        while(t.size()>1&&t.back()==zero) t.pop_back();
        if(s.size()>t.size()) return '>';
        else if(s.size()<t.size()) return '<';
        else {
            if(s==t) return '=';
            else if(s.back()==zero) return '<';
            else if(t.back()==zero) return '>';
            else return '!';
        }
    };

    vector<char> res;
    res.push_back(guess(a.back()));
    res.push_back(guess(b.back()));
    res.push_back(guess(' '));
    debug(res);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    if(res.size()==1) cout<<res.front();
    else cout<<'!';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}