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
string aim="-1";
vector<LL> val;
string op;
LL sum;

LL qpow(__int128 a,__int128 b,__int128 mod) {
    if(a<=0||mod<=0) return -1;
    __int128 res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

LL parse(string s) {
    LL cur=0;
    for(auto x:s) {
        if(x>='0'&&x<='9') cur=cur*10+x-'0';
        else {
            val.push_back(cur),cur=0;
            op.push_back(x);
        }
    }
    val.push_back(cur);
    return cur;
}

void dfs(string s,int idx) {
    if(idx>=s.size()) {
        LL ans=val.front();
        for(int i=0;i<s.size();i++) {
            if(s[i]=='+') ans=ans+val[i+1];
            else if(s[i]=='-') ans=ans-val[i+1];
            else {
                ans=qpow(ans,ans,val[i+1]);
                if(ans==-1) return;
            }
        }
        if(ans==sum) aim=s;
    }
    else {
        string t=s;
        t[idx]='+';
        dfs(t,idx+1);
        t[idx]='-';
        dfs(t,idx+1);
        t[idx]='#';
        dfs(t,idx+1);
    }
}

void solve() {
    string s;
    cin>>s;
    
    int idx=0;
    for(;idx<s.size();idx++) if(s[idx]=='=') break;
    string P,S;
    for(int i=0;i<idx;i++) P.push_back(s[i]);
    for(int i=idx+1;i<s.size();i++) S.push_back(s[i]);

    parse(P);
    sum=parse(S);

    dfs(op,0);
    if(aim=="-1") cout<<"-1"<<endl;
    else {
        aim.push_back('=');
        cout<<val.front();
        for(int i=1;i<val.size();i++) cout<<aim[i-1]<<val[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}