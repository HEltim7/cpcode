#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
string cf[50];

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
    LL n;
    cin>>n;
    int base=1;
    while(qpow(base+1,10)<n) base++;

    int a=0;
    while(qpow(base+1,a+1)*qpow(base,10-(a+1))<=n&&a<=8) a++;
    if(qpow(base+1,a)*qpow(base,10-a)<n) a++;
    
    char ch[]={' ','c','o','d','e','f','o','r','c','e','s'};
    string ans;
    for(int i=1;i<=10;i++)
        if(i<=a) for(int j=1;j<=base+1;j++) ans.push_back(ch[i]);
        else for(int j=1;j<=base;j++) ans.push_back(ch[i]);
    cout<<ans;
    return 0;
}