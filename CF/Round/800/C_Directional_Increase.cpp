#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL arr[N];

void solve() {
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    if(sum) {
        cout<<"No"<<endl;
        return;
    }
    for(int i=n;i>=1;i--) {
        if(arr[i]) {
            if(arr[i]>0) {
                cout<<"No"<<endl;
                return;
            }
            else {
                arr[1]--;
                arr[i]++;
            }
            break;
        }
    }
    for(int i=n;i>=1;i--) {
        sum-=arr[i];
        if(sum<0) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}