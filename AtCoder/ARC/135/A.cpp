#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int mod=998244353;
vector<LL> num;
map<LL,LL> res;

LL dfs(LL x){
    if(x<=4) return x;
    if(res.find(x)!=res.end()) return res[x];
    LL a=dfs(x/2);
    res[x/2]=a;
    LL b=dfs((x+1)/2);
    res[(x+1)/2]=b;
    return a*b%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL x,ans=1;
    cin>>x;
    cout<<dfs(x);
    return 0;
}