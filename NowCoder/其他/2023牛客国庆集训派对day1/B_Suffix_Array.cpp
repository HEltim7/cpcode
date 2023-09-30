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

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

int n,m;
int fir[N],sec[N],cnt[N],sa[N];
vector<int> s(N);

void get_sa() {
    for(int i=1;i<=n;i++) cnt[fir[i]=s[i]]++;
    for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
    for(int i=n;i;i--) sa[cnt[fir[i]]--]=i;

    for(int k=1;k<=n;k<<=1) {
        int num=0;
        for(int i=n-k+1;i<=n;i++) sec[++num]=i;
        for(int i=1;i<=n;i++) if(sa[i]>k) sec[++num]=sa[i]-k;
        for(int i=1;i<=m;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) cnt[fir[i]]++;
        for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i;i--) sa[cnt[fir[sec[i]]]--]=sec[i],sec[i]=0;
        for(int i=1;i<=n;i++) swap(fir[i],sec[i]);
        fir[sa[1]]=num=1;
        for(int i=2;i<=n;i++)
            fir[sa[i]]=(sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+k]==sec[sa[i-1]+k])
                ?num:++num;
        if(num==n) break;
        m=num;
    }
}

void solve(string &t) {
    n=t.size();
    vector<int> suf(2);
    for(int i=n;i>=1;i--) {
        int c=t[i-1]-'a';
        s[i]=suf[c]?suf[c]-i:n;
        suf[c]=i;
    }

    m=++n;
    s[n]=n;
    get_sa();
    for(int i=n-1;i>=1;i--) cout<<sa[i]<<" \n"[i==1];
    for(int i=1;i<=n;i++) fir[i]=sec[i]=sa[i]=cnt[i]=0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while(cin>>s>>s) solve(s);
    return 0;
}