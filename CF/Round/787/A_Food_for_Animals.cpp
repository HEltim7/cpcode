#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--)
    {
        LL a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        x-=min(x,a);
        y-=min(y,b);
        if(x+y<=c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}