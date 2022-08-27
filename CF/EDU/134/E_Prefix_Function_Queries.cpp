#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e6+100;
int pmt[N];

void get_pmt(int n,string &t) {
    for(int i=2,j=0;i<=n;i++) { 
        while(j&&t[i]!=t[j+1]) j=pmt[j]; 
        if(t[i]==t[j+1]) j++; 
        pmt[i]=t[i+1]==t[j+1]?pmt[j]:j; 
    }
}

void get_pmt(int l,int r,string &t) {
    for(int i=l,j=pmt[l-1];i<=r;i++) { 
        debug(j);
        while(j&&t[i]!=t[j+1]) j=pmt[j]; 
        if(t[i]==t[j+1]) j++; 
        pmt[i]=t[i+1]==t[j+1]?pmt[j]:j; 
        cout<<j<<" \n"[i==r];
    }
    debug();
}

void solve() {
    string str;
    cin>>str;
    str=" "+str;
    int n;
    cin>>n;
    int strlen=str.size()-1;
    get_pmt(strlen,str);
    debug(pmt,1,strlen);
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        int len=s.size();
        str+=s;
        get_pmt(strlen+1,str.size()-1,str);
        while(len--) str.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}