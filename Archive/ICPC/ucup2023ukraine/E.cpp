#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    map<int,int> mp;
    int xsum=0;
    for(int i=1;i<=n;i++) cin>>arr[i],xsum^=arr[i];
    
    if(xsum) {
        cout<<"YES"<<endl;
        cout<<2<<endl;
        cout<<"1 1"<<endl;
        cout<<"2 "<<n<<endl;
    }
    else {
        xsum=xsum^arr[n]^arr[n-1];
        mp[arr[n]]=n;
        for(int i=n-2,suf=arr[n]^arr[n-1];i>=1;i--) {
            if(xsum) {
                int cnt=0;
                for(auto [x,idx]:mp) {
                    if(++cnt>3) break;
                    if(x!=0&&x!=xsum) {
                        cout<<"YES"<<endl;
                        cout<<3<<endl;
                        cout<<1<<' '<<i<<endl;
                        cout<<i+1<<' '<<idx-1<<endl;
                        cout<<idx<<' '<<n<<endl;
                        return;
                    }
                }
            }
            mp[suf]=i+1;
            suf^=arr[i];
            xsum^=arr[i];
        }
        cout<<"NO"<<endl;
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