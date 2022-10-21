#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e2+10;

void solve() {
    int n;
    cin>>n;
    deque<int> arr;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr.push_back(in);
    }
    sort(arr.begin(),arr.end(),greater<int>());

    auto check=[&](int x) {
        auto cur=arr;
        while(cur.size()&&cur.front()>x) cur.pop_front();
        while(x) {
            while(cur.size()&&cur.front()>x) cur.pop_front();
            if(cur.empty()) return 0;
            cur.pop_front();
            if(cur.size()) cur.pop_back();
            x--;
        }
        return 1;
    };

    int l=0,r=n;
    while(l<r) {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}