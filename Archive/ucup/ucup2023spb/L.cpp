#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

using LL=long long;

void prepare() {
    string s;
    cin>>s;
    vector<bool> mark(1<<7);
    for(char x:s) {
        if(mark[x]) cout<<1;
        else cout<<0;
        mark[x]=1;
    }
    cout<<endl;
}

void play() {
    string s;
    cin>>s;
    assert(s.size()==50);
    auto ask=[&](int pos) {
        cout<<pos<<endl;
        string s;
        cin>>s;
        if(s.back()=='#') exit(0);
        return s.front();
    };

    vector<int> mp(1<<7);
    auto test=[&](int x,int y) {
        char xc=ask(x);
        char yc=ask(y);
        mp[xc]=x,mp[yc]=y;
        return xc==yc;
    };

    vector<int> zero,one;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='0') zero.emplace_back(i+1);
        else one.emplace_back(i+1);
    }

    for(int i=1;i<zero.size();i+=2) test(zero[i-1], zero[i]);
    for(char i='A';i<='Z';i++) if(!mp[i]) mp[i]=zero.back();

    for(int x:one) ask(mp[ask(x)]);
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    int t;
    cin>>s>>t;
    if(s=="prepare") while(t--) prepare();
    else while(t--) play();
    return 0;
}