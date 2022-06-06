#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int q;
    cin>>q;
    while(q--){
        string s,t;
        cin>>s>>t;
        if(t=="a"){
            cout<<1<<endl;
            continue;
        }
        bool res=1;
        for(auto x:t)
            if(x=='a'){
                cout<<"-1"<<endl;
                res=0;
                break;
            }
        if(!res) continue;
        
        cout<<qpow(2,s.size())<<endl;
    }
    return 0;
}