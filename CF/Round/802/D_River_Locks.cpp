#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL pre[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,q;
    LL maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>pre[i];
        pre[i]+=pre[i-1];
        maxx=max(maxx,(pre[i]+i-1)/i);
    }
    cin>>q;
    while(q--) {
        LL t;
        cin>>t;
        if(t<maxx) cout<<"-1"<<endl;
        else cout<<(pre[n]+t-1)/t<<endl;
    }
    return 0;
}