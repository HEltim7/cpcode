#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define check(x,y) (x!=y&&x+y!=7)
const int mod=1e9+7;
typedef long long LL;
typedef vector<int> VI;

//用C++17交哈希map/set会TLE
//使用C++20或者不用哈希即可AC
unordered_map<string,int> getcolor;
map<LL,VI,greater<LL>> dp;//从节点映射到dp状态
unordered_set<LL> mark;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    getcolor["white"] = 1;
    getcolor["orange"]= 2;
    getcolor["blue"]  = 3;
    getcolor["green"] = 4;
    getcolor["red"]   = 5;
    getcolor["yellow"]= 6;
    int k,m;
    cin>>k>>m;
    while(m--){
        LL idx;
        string color;
        cin>>idx>>color;
        VI t;
        for(int i=0;i<=6;i++){
            if(i==getcolor[color]) t.push_back(1);
            else t.push_back(0);
        }
        dp.emplace(idx,t);
        mark.emplace(idx);
    }

    for(auto [idx,res]:dp){
        if(idx==1) continue;
        LL fa=idx>>1;
        if(mark.find(fa)==mark.end()){
            mark.emplace(fa);
            VI fav;
            fav.push_back(0);
            for(int i=1;i<=6;i++){
                LL tmp=0;
                for(int j=1;j<=6;j++) if(check(i,j)) tmp=(tmp+res[j])%mod;
                fav.push_back(tmp);
            }
            dp.emplace(fa,fav);
        }
        else{
            VI &fav=dp[fa];
            for(int i=1;i<=6;i++){
                LL tmp=0;
                for(int j=1;j<=6;j++) if(check(i,j)) tmp=(tmp+res[j])%mod;
                fav[i]=fav[i]*tmp%mod;
            }
        }
    }
    
    LL node=1;
    for(int i=1;i<=k;i++) node*=2;
    node=node-1-mark.size();
    LL unmark=qpow(4,node);
    LL ans=0;
    for(auto x:dp[1]) ans=(ans+x)%mod;
    cout<<ans*unmark%mod;

    return 0;
}