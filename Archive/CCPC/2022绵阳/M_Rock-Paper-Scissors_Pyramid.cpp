#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
bool win[5][5];
int val[1<<7];

void solve() {
    vector<int> s;
    string t;
    cin>>t;
    s.push_back(val[t.front()]);
    for(int i=1;i<t.size();i++) {
        if(val[t[i]]!=s.back())
            s.push_back(val[t[i]]);
    }

    int ans=0,maxx=0;
    auto work=[&]() {
        for(int i=0,res=0;i<s.size();i++) {
            if(res>=maxx) ans=s[i],maxx=res;
            if(i+1<s.size()) {
                if(win[s[i]][s[i+1]]) res++;
                else res=max(0,res-1);
            }
        }    
    };

    work();
    reverse(s.begin(), s.end());
    work();
    
    // cerr<<ans<<' '<<maxx<<endl;
    ans=(ans+maxx)%3;
    if(ans==0) cout<<'R'<<endl;
    else if(ans==1) cout<<'P'<<endl;
    else if(ans==2) cout<<'S'<<endl;
}

int main() {
    val['R']=0;
    val['P']=1;
    val['S']=2;
    win[0][2]=win[1][0]=win[2][1]=1;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}