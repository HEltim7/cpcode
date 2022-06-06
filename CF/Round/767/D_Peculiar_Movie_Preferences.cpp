#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;

bool check(string s){
    string rs=s;
    reverse(rs.begin(),rs.end());
    return s==rs;
}

void solve() {
    int n;
    cin>>n;
    map<string,string> mp;
    bool ans=0;
    for(int i=1;i<=n;i++){
        string s,t;
        cin>>s;
        t=s;
        if(check(s)) ans=1;
        if(ans) continue;
        string fi,se;
        fi=s.back();
        s.pop_back();
        fi+=s.back();
        s.pop_back();
        se=s;

        auto it=mp.find(fi);
        while(it!=mp.end()&&it->first==fi){
            if(check(it->second+se)) {
                ans=1;
                break;
            }
            else it=next(it);
        }
        fi=t[0];
        fi+=t[1];
        se.clear();
        if(t.size()==3) se=t.back();
        mp.emplace(fi,se);
    }
    cout<<(ans?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}