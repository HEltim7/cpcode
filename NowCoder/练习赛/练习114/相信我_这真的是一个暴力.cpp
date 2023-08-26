#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    vector<int> a(3),b(3);
    for(int i=0;i<3;i++) cin>>a[i];
    for(int i=0;i<3;i++) cin>>b[i];
    for(int i=0;i<3;i++) {
        if(a[i]==b[i]&&a[i]==10) {
            cout<<"Sorry,NoBruteForce"<<endl;
            return;
        }
    }

    double ans=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(i!=j) {
                ans+=(double(a[i])/10)*(double(b[j])/10);
            }
        }
    }
    ans=1/ans;
    cout<<fixed<<setprecision(15)<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}