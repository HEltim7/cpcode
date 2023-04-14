#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
pair<int,int> arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i].second;
    for(int i=1;i<=n;i++) cin>>arr[i].first;
    sort(arr+1,arr+1+n);
    int sum=0;
    for(int i=1;i<=n;i++) {
        if(sum<arr[i].second) {
            if(sum!=0) k-=arr[i].first;
            auto get=[&](int x) {
                return 1LL*(k+k-x*arr[i].first)*(x+1)/2;
            };

            int t=k/arr[i].first;
            LL maxx=get(t);
            if(sum+maxx<arr[i].second) {
                cout<<"NO"<<endl;
                return;
            }
            
            int l=0,r=t;
            while(l<r) {
                int mid=l+r>>1;
                LL maxx=get(mid);
                if(sum+maxx<arr[i].second) l=mid+1;
                else r=mid;
            }
            sum+=get(l);
            k-=l*arr[i].first;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}