#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=8e5+10;

int n,m=1<<7;
string s;
int fir[N],sec[N],cnt[N];
int sa[N],rk[N],height[N];
int suf[N];

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
        swap(fir,sec);
        fir[sa[1]]=num=1;
        for(int i=2;i<=n;i++)
            fir[sa[i]]=(sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+k]==sec[sa[i-1]+k])
                ?num:++num;
        if(num==n) break;
        m=num;
    }
}

void get_height() {
    for(int i=1;i<=n;i++) rk[sa[i]]=i;
    for(int i=1,k=0;i<=n;i++) {
        if(rk[i]==1) continue;
        if(k) k--;
        int j=sa[rk[i]-1];
        while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

void solve() {
    s=" ";
    int t;
    string S,T;
    cin>>t>>S>>T;
    S+=S;
    S.pop_back();
    T+=T;
    T.back()='|';
    s=s+T+S;
    n=s.size()-1;

    get_sa();
    get_height();
    for(int i=1;i<=t;i++) suf[rk[i]]++;
    for(int i=n;i>=1;i--) suf[i]+=suf[i+1];
    LL ans=0;
    for(int i=2*t+1;i<=3*t;i++) ans+=suf[rk[i]];
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}