#include <algorithm>
#include <array>
#include <cassert>
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
constexpr int N=2e5+10;
int ans[N];

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;

    int l=0,r=0;
    bool pos=0,neg=0;
    for(int i=1,pre=0;i<=n;i++) {
        int cur=0;
        if(s[i]=='(') cur=1,l++;
        else cur=-1,r++;
        if(pre+cur>0) {
            pos=1;
            ans[i]=2;
        }
        else if(pre+cur<0) {
            neg=1;
            ans[i]=1;
        }
        else ans[i]=ans[i-1];
        pre+=cur;
    }
    if(l!=r) {
        cout<<-1<<endl;
        return;
    }

    int tot=int(pos)+int(neg);
    cout<<tot<<endl;
    if(tot==1) for(int i=1;i<=n;i++) ans[i]=1;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}