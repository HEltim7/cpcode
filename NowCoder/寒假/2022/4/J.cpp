#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int mod=1e9+7;

inline bool check(int x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return 1;
    }
    return 0;
}

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL l,r,ans=1;
    cin>>l>>r;
    int cnt=0;
    vector<LL> num;
    for(int i=l;i<=r;i++) if(check(i)) num.push_back(i),cnt++;
    if(cnt==0) cout<<-1;
    else{
        // for(auto x:num) ans=lcm(ans,x)%mod;
        for(auto x:num){
            ans=((ans*x%mod)*qpow(gcd(ans,x)%mod,mod-2))%mod;
            if(ans<0) debug(ans);
        }
        cout<<ans;
    }
    return 0;
}

/*

*/