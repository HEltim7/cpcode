#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n,m,x,y,str,stc,edr,edc;
    while(cin>>n>>m>>x>>y>>str>>stc>>edr>>edc) {
        auto rev=[&](LL &val,LL maxx) {
            val=maxx-val+1;
        };

        if(edr<str) rev(x,n),rev(str,n),rev(edr,n);
        if(edc<stc) rev(y,m),rev(stc,m),rev(edc,m);

        auto dis=[&](LL x,LL y,LL r,LL c) {
            return abs(r-x)+abs(c-y);
        };

        LL ans=0;
        if(str==edr) {
            ans=dis(x,y,str,stc+1);
            ans+=dis(str,stc,edr,edc)*5-4;
            if(x==str&&y<stc) ans+=2;
        }
        else if(stc==edc) {
            ans=dis(x,y,str+1,stc);
            ans+=dis(str,stc,edr,edc)*5-4;
            if(y==stc&&x<str) ans+=2;
        }
        else {
            LL len=min(edr-str,edc-stc)*2;
            LL rest=dis(str,stc,edr,edc)-len;
            assert(len>0);
            LL res=dis(x,y,str+1,stc);
            if(y==stc&&x<str) res+=2;
            res+=len*3-2;
            res+=rest*5;
            if(edr-str>edc-stc) res-=2;

            ans=dis(x,y,str,stc+1);
            if(x==str&&y<stc) ans+=2;
            ans+=len*3-2;
            ans+=rest*5;
            if(edc-stc>edr-str) ans-=2;

            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}