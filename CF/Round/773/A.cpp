#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        if(b==d){
            if(f<b) cout<<abs(a-c)<<endl;
            else cout<<0<<endl;
        }
        else if(d==f) {
            if(b<d) cout<<abs(c-e)<<endl;
            else cout<<0<<endl;
        }
        else if(b==f) {
            if(d<b) cout<<abs(a-e)<<endl;
            else cout<<0<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}