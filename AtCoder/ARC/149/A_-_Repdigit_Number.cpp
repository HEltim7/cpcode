#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> ans;
    for(int d=9;d>=1;d--) {
        LL len=0,r=0;
        while((r!=0||len==0)&&(len<=n)) {
            r=(r*10+d)%m;
            len++;
        }
        if(len>n) continue;
        else {
            LL cnt=n/len*len;
            ans.push_back(string(cnt,d+'0'));
        }
    }
    if(ans.empty()) cout<<"-1"<<endl;
    else {
        sort(ans.begin(),ans.end(),[](string &s,string &t) {
            if(s.length()!=t.length()) return s.length()>t.length();
            else return s.front()>t.front();
        });
        cout<<ans.front()<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}