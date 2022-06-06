#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int x,y;
    cin>>x>>y;
    while(x) cout<<x--<<' '<<y<<endl;
    while(y) cout<<x<<' '<<y--<<endl;
    for(int i=0;i<=9;i++){
        if(i&1) for(int j=9;~j;j--) cout<<i<<' '<<j<<endl;
        else for(int j=0;j<=9;j++) cout<<i<<' '<<j<<endl;
    }
    return 0;
}