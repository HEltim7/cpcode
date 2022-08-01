#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <array>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

#define endl '\n'
using LL=long long;
mt19937 gen(random_device{}());
const int N=1e6+10;
int pre[3][N];

template<int NUM,int MAX=127,class T=mt19937> struct HashArray {
    using ULL=unsigned long long;
    using ARR=array<ULL,NUM>;
    T gen;
    int P[NUM];
    vector<ULL> val[NUM];

    ULL qpow(ULL a,ULL b) {
        ULL res=1;
        while(b) {
            if(b&1) res=res*a;
            b>>=1;
            a=a*a;
        }
        return res;
    }
    void init() {
        for(int i=0;i<NUM;i++) {
            val[i].push_back(0);
            P[i]=gen();
            while(P[i]<=MAX) P[i]=gen();
        }
    }

    void push_back(int x) {
        for(int i=0;i<NUM;i++) {
            ULL t=val[i].back();
            val[i].push_back(t*P[i]+x);
        }
    }
    
    void append(string &x) {
        for(auto s:x) push_back(s);
    }

    ARR query(int l,int r) {
        ARR res;
        for(int i=0;i<NUM;i++) res[i]=(val[i][r]-val[i][l-1]*qpow(P[i],r-l+1));
        return res;
    }

    bool match(int l,int r,int L,int R) {
        return query(l,r)==query(L, R);
    }

    HashArray(T x): gen(x) { init(); }
};

void solve() {
    int n;
    string tmp;
    while(cin>>n>>tmp) {
        string str;
        for(auto x:tmp) str.push_back('|'),str.push_back(x);
        str.push_back('|');
        HashArray<1> s(gen);
        HashArray<1> t(s);
        n=str.size()-1;
        for(int i=1;i<=n;i++) {
            pre[0][i]=(str[i]=='k')+pre[0][i-1];
            pre[1][i]=(str[i]=='f')+pre[1][i-1];
            pre[2][i]=(str[i]=='c')+pre[2][i-1];
        }
        s.append(str);
        reverse(str.begin(),str.end());
        t.append(str);
        LL ans[3]={0,0,0};
        for(int i=1;i<=n;i++) {
            int l=0,r=min(i-1,n-i);
            while(l<r) {
                int mid=l+r+1>>1;
                if(s.query(i-mid, i)==t.query(n-i-mid, n-i)) l=mid;
                else r=mid-1;
            }
            for(int z=0;z<3;z++) ans[z]+=pre[z][i+l]-pre[z][i-1];
        }
        for(int z=0;z<3;z++) cout<<ans[z]<<" \n"[z==2];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}