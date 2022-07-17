#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=2e5+10;
int sa[N],fk[N],sk[N],cnt[N];
int n,m;
string s;

void get_sa() {
    for(int i=1;i<=n;i++) cnt[fk[i]=s[i]]++;
    for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n;i;i--) sa[cnt[fk[i]]--]=i;
    
    for(int k=1;k<n;k<<=1) {
        int num=0;
        for(int i=n-k+1;i<=n;i++) sk[++num]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) sk[++num]=sa[i]-k;
        for(int i=1;i<=m;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) cnt[fk[i]]++;
        for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i;i--) sa[cnt[fk[sk[i]]]--]=sk[i],sk[i]=0;
        swap(fk,sk);
        fk[sa[1]]=num=1;
        for(int i=2;i<=n;i++) fk[sa[i]]=(sk[sa[i]]==sk[sa[i-1]]&&
            (sa[i]+k<=n?sk[sa[i]+k]:0)==(sa[i-1]+k<=n?sk[sa[i-1]+k]:0))
            ?num:++num;
        if(n==num) break;
        m=num;
    }
}

void solve() {
    cin>>s;
    int len=s.size();
    s=" "+s+s;
    n=s.size()-1;
    m=1<<7;
    get_sa();
    string ans;
    for(int i=1;i<=n;i++) if(sa[i]<=len) ans.push_back(s[sa[i]+len-1]);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}