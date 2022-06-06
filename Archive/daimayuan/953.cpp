#pragma GCC optimize("Ofast")
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int get(int val) {
    int res=0;
    for(int i=2;i*i<=val&&val>1;i++) {
        if(val%i==0) {
            while(val%i==0) val/=i;
            res++;
        }
    }
    return res+(val>1);
}

int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

void solve() {
    int x,y,k,ans=0;
    cin>>x>>y>>k;
    for(int i=1;i*i<=k;i++) {
        if(k%i==0) {
            int t=k/i+y;
            if(t%x==0) ans+=qpow(2,get(t/x));
            if(i*i!=k) {
                t=i+y;
                if(t%x==0) ans+=qpow(2,get(t/x));
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}