#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[10],ch[10];

void solve() {
    int n;
    cin>>n;
    set<string> st;
    for(int i=1;i<=n;i++) {
        string s;
        for(int j=1;j<=5;j++) {
            cin>>s;
            st.insert(s);
        }
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++) {
        string s;
        int pos;
        cin>>s>>pos;
        if(st.find(s)==st.end()) cnt[pos]++;
        else cnt[pos]++,ch[pos]++;
    }
    
    int res=1e9,tot=0;
    for(int i=1;i<=5;i++) res=min(res,cnt[i]);
    for(int i=1;i<=5;i++) ch[i]=min(ch[i],res);
    for(int i=1;i<=5;i++) tot+=ch[i];
    cout<<min(res,tot);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}