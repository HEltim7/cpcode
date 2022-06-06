#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int l,r,k;
        cin>>l>>r>>k;
        if(r==1) cout<<"NO"<<endl;
        else if(l==r) cout<<"YES"<<endl;
        else{
            int cnt=(r-l+1)>>1;
            if(((r-l+1)&1)&&(l&1)) cnt++;
            if(k>=cnt) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}