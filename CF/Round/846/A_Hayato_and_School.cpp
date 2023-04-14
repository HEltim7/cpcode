#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=330;
int arr[N];

void solve() {
    int n,odd=0,even=0;
    cin>>n;

    vector<int> oddv,evenv;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in&1) odd++,oddv.push_back(i);
        else even++,evenv.push_back(i);
    }

    if(odd>=3||(even>=2&&odd>=1)) {
        cout<<"YES"<<endl;
        if(odd>=3) {
            for(int i=0;i<3;i++) cout<<oddv[i]<<' ';
            cout<<endl;
            return;
        }
        for(int i=0;i<2;i++) cout<<evenv[i]<<' ';
        cout<<oddv.front()<<endl;
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