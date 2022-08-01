#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int M=1e7;
vector<int> ans;

void solve() {
    int n;
    LL m;
    cin>>n>>m;
    if(n==1) cout<<m;
    else if(m>=M) {
        for(int i=M;i;i--) {
            if(m<i) {
                if(m+ans.back()<=M) {
                    cout<<m+ans.size()<<' ';
                    for(auto x:ans) cout<<x-1<<' ';
                }
                else {
                    cout<<m<<' ';
                    for(auto x:ans) cout<<x<<' ';
                }
            }
            else ans.push_back(i),m-=i;
        }
    }
    else if(m<=n) {
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}