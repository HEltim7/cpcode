#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
LL mod=1e9+7;

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
    cin.tie(nullptr);
    LL cnt=-1,sum=0;
    bool flag=1;
    string str;
    cin>>str;
    for(auto x:str) {
        if(x=='(') sum++;
        else sum--;
        if(sum<0) flag=0;
        if(sum==0) cnt++;
    }
    if(cnt==-1||flag==0||sum) cout<<-1;
    else cout<<qpow(2,cnt);
    return 0;
}