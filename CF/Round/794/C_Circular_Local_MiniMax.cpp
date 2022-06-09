#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=1e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    vector<int> ans;
    for(int i=1,endi=(n+1)/2,j=endi+1;i<=endi||j<=n;) {
        if(i<=endi) ans.push_back(arr[i++]);
        if(j<=n)  ans.push_back(arr[j++]);
    }
    bool flag=1;
    for(int i=0;i<n;i++) 
        if(!(ans[i]>ans[(i-1+n)%n]&&ans[i]>ans[(i+1)%n]
        ||ans[i]<ans[(i-1+n)%n]&&ans[i]<ans[(i+1)%n])) flag=0;
    if(flag) {
        cout<<"YES"<<endl;
        for(auto x:ans) cout<<x<<' ';
        cout<<endl;
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