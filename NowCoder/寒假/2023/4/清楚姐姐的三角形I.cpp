#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    vector<LL> v(3),l(3);
    for(auto &x:v) cin>>x;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++)
            if(i==j) l[i]-=v[j];
            else l[i]+=v[j];

        if((l[i]+1)/2!=l[i]/2) {
            cout<<"No"<<endl;
            return;
        }
        l[i]/=2;
    }

    auto t=l;
    sort(t.begin(),t.end());
    if(t[2]<t[0]+t[1]) {
        cout<<"Yes"<<endl;
        for(int i=0;i<3;i++) cout<<l[i]<<" \n"[i==2];
    }
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}