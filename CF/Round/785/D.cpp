#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e9+7,mod=1e9+7;

#define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void get(map<LL,int> &t,LL num){
    LL tmp=num;
    for(int i=2;i<=num/i&&tmp>1;i++){
        if(tmp%i==0){
            auto it=t.insert({i,1}).first;
            tmp/=i;
            while(tmp%i==0){
                it->second++;
                tmp/=i;
            }
        }
    }
    if(tmp>1) t.insert({tmp,1});
}

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void solve(){
    LL b,difb,terb;
    LL c,difc,terc;
    cin>>b>>difb>>terb;
    cin>>c>>difc>>terc;
    LL bend=b+(terb-1)*difb;
    LL cend=c+(terc-1)*difc;
    
    map<LL,int> bs,cs;
    get(bs,difb);get(cs,difc);
    // debug(bend,cend);
    debug(bs);
    debug(cs);

    if(c<b||cend>bend||(c-b)%difb) {cout<<0<<endl;return;}
    for(auto [x,y]:bs){
        auto it=cs.find(x);
        if(it==cs.end()||y>it->second){
            cout<<0<<endl;
            return;
        }
    }
    if(b>c-difc||bend<cend+difc) {cout<<"-1"<<endl;return;}
    // cout<<"qwq"<<endl;
    LL sum=1,cnt=0;
    for(auto [x,y]:cs){
        auto it=bs.find(x);
        if(it!=bs.end()&&y<=it->second){
            LL t=(qpow(x,2*y+2)-1+mod)%mod*qpow((x*x%mod-1+mod)%mod,mod-2)%mod;
            debug(t);
            sum=(sum*t)%mod;
        }
    }
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}