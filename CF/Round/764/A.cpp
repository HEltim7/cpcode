#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,in;
    cin>>t;
    while(t--){
        cin>>n;
        int maxx=0,minn=1e9+1;
        for(int i=1;i<=n;i++){
            cin>>in;
            maxx=max(maxx,in);
            minn=min(minn,in);
        }
        cout<<maxx-minn<<endl;
    }
    return 0;
}