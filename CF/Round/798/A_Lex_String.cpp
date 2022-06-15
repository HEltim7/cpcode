#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    string s[2];
    cin>>s[0]>>s[1];
    sort(s[0].begin(),s[0].end(),greater<char>());
    sort(s[1].begin(),s[1].end(),greater<char>());
    for(int cnt=0,cur=0;s[0].size()&&s[1].size();) {
        if(cnt>=k||s[cur].back()>s[!cur].back()) {
            cur=!cur;
            cout<<s[cur].back();
            s[cur].pop_back();
            cnt=1;
        }
        else if(s[cur].back()<s[!cur].back()) {
            cout<<s[cur].back();
            s[cur].pop_back();
            cnt++;
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}