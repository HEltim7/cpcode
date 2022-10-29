#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

void solve() {
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        if(s.empty()||s.back()!=in) s.push_back(in);
    }
    
    int res=0;
    if(s.front()=='1') res=s.size()-1;
    else res=s.size()-2;

    cout<<max(0,res)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}