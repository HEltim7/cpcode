#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#define endl '\n'
using LL = long long;
constexpr int mod=998244353;
char mp[1<<7];
int id[1<<7];
array<array<array<int,10+26+26>, 8>, 2> dp;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    
    int idx=0;
    for(char i='0';i<='9';i++) id[mp[idx]=i]=idx,idx++;
    for(char i='a';i<='z';i++) id[mp[idx]=i]=idx,idx++;
    for(char i='A';i<='Z';i++) id[mp[idx]=i]=idx,idx++;

    auto add=[&](int &x,int y) {
        x+=y;
        x-=x>=mod?mod:0;
    };
    auto sub=[&](int x,int y) {
        x-=y;
        x+=x<0?mod:0;
        return x;
    };

    char x=s.front();
    if(isdigit(x)) dp[0][1<<2][id[x]]=1;
    if(isupper(x)) dp[0][1<<1][id[x]]=1;
    if(islower(x)) dp[0][1<<1][id[toupper(x)]]=dp[0][1<<0][id[x]]=1;
    if(x=='?') {
        for(int c=id['0'];c<=id['9'];c++) dp[0][1<<2][c]=1;
        for(int c=id['A'];c<=id['Z'];c++) dp[0][1<<1][c]=1;
        for(int c=id['a'];c<=id['z'];c++) dp[0][1<<0][c]=1;
    }

    for(int i=1;i<n;i++) {
        auto &cur=dp[i&1^1];
        auto &ne=dp[i&1];
        for(int st=0;st<8;st++) fill(ne[st].begin(),ne[st].end(),0);
        x=s[i];
        idx=id[x];
        if(isdigit(x)) for(int st=0;st<8;st++) for(int c=0;c<62;c++) if(mp[c]!=x) add(ne[1<<2|st][idx],cur[st][c]);
        if(isupper(x)) for(int st=0;st<8;st++) for(int c=0;c<62;c++) if(mp[c]!=x) add(ne[1<<1|st][idx],cur[st][c]);
        if(islower(x)) {
            for(int st=0;st<8;st++) for(int c=0;c<62;c++) if(mp[c]!=x) add(ne[1<<0|st][idx],cur[st][c]);
            x=toupper(x),idx=id[x];
            for(int st=0;st<8;st++) for(int c=0;c<62;c++) if(mp[c]!=x) add(ne[1<<1|st][idx],cur[st][c]);
        }
        if(x=='?') {
            for(int st=0;st<8;st++) {
                int sum=0;
                for(int c=0;c<62;c++) add(sum,cur[st][c]);
                for(int c=id['0'];c<=id['9'];c++) add(ne[1<<2|st][c],sub(sum,cur[st][c]));
                for(int c=id['A'];c<=id['Z'];c++) add(ne[1<<1|st][c],sub(sum,cur[st][c]));
                for(int c=id['a'];c<=id['z'];c++) add(ne[1<<0|st][c],sub(sum,cur[st][c]));
            }
        }
    }

    int ans=0;
    for(int c=0;c<62;c++) add(ans,dp[(n-1)&1][7][c]);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}