#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n;
    cin>>n;
    if(n%2==0) {
        cout<<n/2<<' '<<n/2<<endl;
    }
    else {
        vector<LL> num;
        while(n) num.push_back(n%10),n/=10;

        LL a=0,b=0,cnt=0,pw=1;
        for(auto x:num) {
            if(x%2==cnt%2) {
                cnt=0;
                b+=(x+1)/2*pw;
                a+=x/2*pw;
            }
            else {
                cnt=1;
                a+=(x+1)/2*pw;
                b+=x/2*pw;
            }
            pw*=10;
        }
        cout<<a<<' '<<b<<endl;
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