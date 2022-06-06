#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10,mod=998244353;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

LL get(string &s){
    LL res=0;
    for(int i=0;i<(s.size()+1)/2;i++)
        res=(res+(s[i]-'A')*qpow(26,s.size()-2*i-1>>1)%mod)%mod;
    int cnt=0;
    if(s.size()&1){
        int mid=s.size()/2;
        string l,r;
        for(int i=mid-1;i>=0;i--) l.push_back(s[i]);
        for(int i=mid+1;i<s.size();i++) r.push_back(s[i]);
        cnt=l<=r;
    }
    else{
        int mid=s.size()/2;
        string l,r;
        for(int i=mid-1;i>=0;i--) l.push_back(s[i]);
        for(int i=mid;i<s.size();i++) r.push_back(s[i]);
        cnt=l<=r;
    }
    return (res+cnt)%mod; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        cout<<get(s)<<endl;
    }
    return 0;
}