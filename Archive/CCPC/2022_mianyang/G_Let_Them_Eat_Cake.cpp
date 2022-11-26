#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

void solve() {
    int n,ans=0;
    cin>>n;

    auto work=[&](vector<int> &arr) {
        if(arr.size()==1) return vector<int>{};
        vector<int> res;
        for(int i=0;i<arr.size();i++) {
            if(i-1>=0&&arr[i]<arr[i-1]||i+1<arr.size()&&arr[i]<arr[i+1])
                continue;
            res.push_back(arr[i]);
        }
        ans++;
        return res;
    };
    vector<int> arr;
    for(int i=1;i<=n;i++) {
        int  in;
        cin>>in;
        arr.push_back(in);
    }
    while(arr.size()) arr=work(arr);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}