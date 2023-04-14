#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
constexpr int N=310;
pair<int,int> arr[N];

void solve() {
    int n;
    cin>>n;
    string s(n,'1');
    for(int i=1;i<n;i++) {
        s[i-1]='0';
        cout<<"? "<<i<<' '<<s<<endl;
        s[i-1]='1';
    }
    arr[n].first=n*(n-1)/2;
    for(int i=1;i<=n;i++) arr[i].second=i;
    for(int i=1;i<n;i++) cin>>arr[i].first,arr[n].first-=arr[i].first;
    sort(arr+1,arr+1+n,greater<>());
    for(int i=1,sum=0;i<=n;i++) {
        sum+=arr[i].first;
        if(sum==i*(i-1)/2+i*(n-i)) {
            string ans(n,'0');
            for(int j=1;j<=i;j++) ans[arr[j].second-1]='1';
            cout<<"! "<<ans<<endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}