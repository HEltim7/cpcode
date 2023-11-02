#include <vector>
#include <cstring>
#include <numeric>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL p,q;
    cin>>p>>q;
    string s=to_string(p);
    string t=to_string(q);
    int n=s.size();
    int m=t.size();
    LL ans=p;
    LL g=gcd(p,q);
    LL a=p/g;
    LL b=q/g;

    string xs,ys,xd,yd;
    for(int i=1;i<(1<<n)-1;i++) {
        xs.clear();
        xd.clear();
        for(int j=0;j<n;j++) {
            if(i>>j&1) xd.push_back(s[j]);
            else xs.push_back(s[j]);
        }
        LL x=stoll(xs);
        if(!x||x%a) continue;
        LL y=x/a*b;

        ys=to_string(y);
        int zero=m-int(ys.size())-int(xd.size());
        if(zero<0) continue;
        ys=string(zero,'0')+ys;
        
        yd.clear();
        for(int j=0,k=0;j<m;j++) {
            if(k<ys.size()&&t[j]==ys[k]) k++;
            else yd.push_back(t[j]);
        }
        sort(xd.begin(),xd.end());
        sort(yd.begin(),yd.end());
        if(xd==yd) ans=min(ans,x);
    }
    cout<<ans<<' '<<ans/a*b<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--) solve();
    return 0;
}