#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,K=1e3+10;
int arr[K];

void solve() {
    int n,k;
    cin>>n>>k;
    LL sum=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr[in%k]++;
        sum+=in;
    }
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++) {
            int r=(k-j+i)%k;
            if(j==r) {
                int t=arr[j]/2;
                sum-=1LL*t*i;
                arr[j]-=t;
            }
            else {
                int t=min(arr[j],arr[r]);
                sum-=1LL*t*i;
                arr[j]-=t,arr[r]-=t;
            }
        }
    cout<<sum/k<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}