#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    LL k,x;
    cin>>n>>k>>x;
    string in;
    cin>>in;

    if(x==1) {
        for(auto x:in) if(x=='a') cout<<x;
        cout<<endl;
        return ;
    }

    vector<LL> seg,val;
    for(int i=0,cnt=0;i<n;i++) {
        if(in[i]=='*') cnt++;
        else {
            if(cnt) seg.push_back(cnt);
            seg.push_back(-1);
            cnt=0;
        }
        if(i==n-1&&cnt) seg.push_back(cnt);
    }
    val=seg;
    
    x--;
    LL suf=1;
    debug(seg);
    
    for(int i=seg.size()-1;i>=0;i--) {
        if(seg[i]>=1) {
            val[i]=suf;
            bool flag=suf>x/(k*seg[i]+1);
            suf*=1LL*seg[i]*k+1;
            
            if(flag) {
                debug(i,suf);
                for(int j=0;j<i;j++) if(seg[j]==-1) cout<<'a';
                for(int z=i;z<seg.size();z++) {
                    if(seg[z]==-1) cout<<'a';
                    else {
                        LL t=x/val[z];
                        assert(t<=k*seg[z]);
                        debug(z,t,x,val[z]);
                        for(int j=0;j<t;j++) cout<<'b';
                        x-=val[z]*t;
                    }
                }
                cout<<endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}