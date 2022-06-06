#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==0&&y==0) cout<<0<<endl;
        else{
            int t=(int)sqrt(x*x+y*y);
            if(t*t==x*x+y*y) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}