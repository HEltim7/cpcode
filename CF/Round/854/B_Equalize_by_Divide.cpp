#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    
    vector<int> v;
    for(int i=1;i<=n;i++) cin>>arr[i],v.push_back(arr[i]);
    sort(v.begin(),v.end());
    int minn=v.front();
    v.erase(unique(v.begin(),v.end()),v.end());
    if(v.size()==1) cout<<0<<endl;
    else if(minn==1) cout<<-1<<endl;
    else {
        auto find=[&]() {
            int minn=arr[1];
            int idx=1;
            for(int i=2;i<=n;i++) {
                if(arr[i]<minn) {
                    idx=i;
                    minn=arr[i];
                }
            }
            return idx;
        };

        bool flag=1;
        vector<pair<int,int>> op;
        while(flag) {
            flag=0;
            int idx=find();
            for(int i=1;i<=n;i++) {
                if(i!=idx) {
                    while(arr[i]>arr[idx]) {
                        arr[i]=(arr[i]+arr[idx]-1)/arr[idx];
                        op.emplace_back(i,idx);
                        flag=1;
                    }
                }
            }
        }

        cout<<op.size()<<endl;
        assert(op.size()<=n*30);
        for(auto [x,y]:op) cout<<x<<' '<<y<<endl;
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