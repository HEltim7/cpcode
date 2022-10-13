#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    n*=2;
    int cnt[]={0,0};

    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        arr[i]=in=='1';
        cnt[arr[i]]++;
    }
    if(cnt[0]&1||cnt[1]&1) {
        cout<<"-1"<<endl;
        return;
    }

    vector<int> up,dn,pos;
    auto split=[&]() {
        up.clear(),dn.clear();
        for(int i=1;i<=n;i++) {
            if(up.size()==dn.size()) up.push_back(arr[i]);
            else if(arr[i]==up[dn.size()]) dn.push_back(arr[i]);
            else up.push_back(arr[i]);
        }
    };

    auto output=[&]() {
        cout<<pos.size()<<' ';
        for(auto x:pos) cout<<x<<' ';
        cout<<endl;
        for(auto x:up) cout<<x<<' ';
        cout<<endl;
    };

    split();
    if(up.size()!=dn.size()) {
        
    }
    output();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}