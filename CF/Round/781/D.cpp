#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

using LL=long long;
const int N=29;

void solve() {
    int ans=0,h=1<<N;
    for(int i=0;i<=N;i++) {
        int a=h-ans;
        int b=(1<<i+1)+a;
        cout<<"? "<<a<<' '<<b<<endl;
        int in;
        cin>>in;
        if(i!=N&&in<(1<<i+1)) ans+=1<<i;
        else if(i==N&&in==(1<<i+1)) ans+=1<<i;
    }
    cout<<"! "<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}