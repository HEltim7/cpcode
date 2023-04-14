#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[1<<7];

void solve() {
    int n;
    string s;
    cin>>n>>s;

    auto check=[](string s) {
        for(char i='0';i<='9';i++) cnt[i]=0;
        int res=0,dif=0,ans=0;
        for(auto x:s) {
            cnt[x]++;
            res=max(res,cnt[x]);
            if(cnt[x]==1) dif++;
            ans+=res<=dif;
        }
        return ans;
    };

    int ans=0;
    for(int i=0;i<n;i++) {
        string str;
        for(int j=i;i-j<=120&&j>=0;j--) str.push_back(s[j]);
        ans+=check(str);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}