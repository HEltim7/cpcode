#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];
int suf[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(arr[i]!=arr[i+1]);

    bool ans=0;
    for(int i=0;i<=n;i++){
        if(i&&arr[i]%2==i%2) break;
        if(suf[i+1]<=i&&suf[i+1]%2==i%2){
            ans=1;
            break;
        }
    }
    
    if(ans) cout<<"Yes";
    else cout<<"No";
    return 0;
}