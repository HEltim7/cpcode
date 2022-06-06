#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VII;
int n;

inline LL cal(string &s){
    LL res=0;
    s.back()='R';
    PII last={1,1};
    VII p;
    for(auto x:s){
        if(x=='R') p.push_back(last),last.second++;
        else last.first++;
    }
    int len=n-p.back().first;
    for(auto [row,col]:p){
        if(row!=1) res+=n-(row+len);
        else res+=n-row;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>n>>s;
        bool flag=1;
        for(auto x:s) if(s.front()!=x) flag=0;
        if(flag){
            cout<<n<<endl;
            continue;
        }
        s.push_back('R');
        LL ans=(LL)n*n;
        ans-=cal(s);
        for(auto &x:s) x=x=='R'?'D':'R';
        ans-=cal(s);
        cout<<ans<<endl;
    }
    return 0;
}