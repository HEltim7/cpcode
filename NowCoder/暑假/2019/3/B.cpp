#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int fir[N];

void solve() {
    int n,a=0,b=0,sum=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++) {
        sum+=s[i]=='1'?1:-1;
        if(!fir[sum]) fir[sum]=i+1;
        else a=max(a,i+1-fir[sum]);
        if(sum==0) a=max(a,i+1);
    }
    b=n-abs(sum);
    cout<<a<<' '<<b<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}