#include<iostream>
using namespace std;

#define endl '\n'

inline bool check(int x,int aim){
    if(x==aim) return 1;
    if(aim<=0) return 0;
    if(aim%x) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        bool ans=0;
        d=c-b;
        ans=max(ans,check(a,b-d));
        d=c-a;
        if(d%2==0){
            d/=2;
            ans=max(ans,check(b,c-d));
        }
        d=b-a;
        ans=max(ans,check(c,b+d));
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}