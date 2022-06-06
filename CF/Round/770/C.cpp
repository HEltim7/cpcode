#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve(){
    int row,col;
    cin>>row>>col;
    if(col==1){
        cout<<"YES"<<endl;
        for(int i=1;i<=row;i++)
            cout<<i<<endl;
    }
    else if(row&1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int idx=1;
        for(int i=1;i<=row;i+=2){
            for(int j=1;j<=col;j++) 
                cout<<idx+(j-1)*2<<" \n"[j==col];
            for(int j=1;j<=col;j++)
                cout<<idx+1+(j-1)*2<<" \n"[j==col];
            idx+=2*col;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}