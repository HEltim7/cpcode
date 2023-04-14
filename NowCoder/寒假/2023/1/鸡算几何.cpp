#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
LD x[2][10],y[2][10];
LD u[10],v[10];
constexpr LD eps=1e-9;

void solve() {
    for(int i=0;i<3;i++) cin>>x[0][i]>>y[0][i];
    for(int i=0;i<3;i++) cin>>x[1][i]>>y[1][i];

    LD len1,len2;
    
    auto cal_len=[&](int i) {
        len1=(y[i][0]-y[i][1])*(y[i][0]-y[i][1])+(x[i][0]-x[i][1])*(x[i][0]-x[i][1]);
        len2=(y[i][1]-y[i][2])*(y[i][1]-y[i][2])+(x[i][1]-x[i][2])*(x[i][1]-x[i][2]);
    };
    cal_len(0);
    if(abs(len1-len2)<=eps) {
        cout<<"NO"<<endl;
        return;
    }

    auto cal=[&](int i) {
        cal_len(i);
        int s=len1<len2?0:2;
        int t=len1<len2?2:0;
        u[0]=x[i][s]-x[i][1];
        v[0]=y[i][s]-y[i][1];
        u[1]=x[i][t]-x[i][1];
        v[1]=y[i][t]-y[i][1];
        return u[0]*v[1]-u[1]*v[0];
    };

    if(abs(cal(0)-cal(1))<=eps) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}