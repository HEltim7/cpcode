#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];
bool mark[N];

void solve() {
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++) mark[i]=0;
    vector<pair<int,int>> ans;
    for(int i=1;i<=n&&ans.size()<k-1;i++) 
        if(!mark[i]&&(i^x)<=n&&(i^x)>=1&&!mark[i^x]) {
            ans.emplace_back(i,i^x);
            mark[i]=mark[i^x]=1;
        }

    if(ans.size()<k-1) cout<<"NO"<<endl;
    else {
        int sum=0;
        vector<int> res;
        for(int i=1;i<=n;i++) if(!mark[i]) sum^=i,res.push_back(i);
        if(sum!=x) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            for(auto [x,y]:ans) cout<<2<<' '<<x<<' '<<y<<endl;
            cout<<res.size()<<' ';
            for(auto x:res) cout<<x<<' ';
            cout<<endl;
        }
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