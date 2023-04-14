#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e6+10;
int link[N],pre[N];

void kmp_build(int n,string &t) {
    for(int i=2,j=0;i<=n;i++) {
        while(j&&t[i]!=t[j+1]) j=link[j];
        if(t[i]==t[j+1]) j++;
        link[i]=j; 
    }
}

void solve() {
    int q;
    string s;
    cin>>s>>q;
    s=" "+s;
    int n=s.size()-1;
    kmp_build(n, s);

    for(int len=link[n];len;len=link[len]) pre[len]++;
    for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
    while(q--) {
        int idx;
        cin>>idx;
        idx=min(idx-1,n-idx);
        cout<<pre[idx]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}