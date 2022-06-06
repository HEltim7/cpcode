#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<=n;i++) if(arr[i]<0) cnt++;
        for(int i=1;i<=n;i++) {
            if(cnt>0) arr[i]=-abs(arr[i]);
            else arr[i]=abs(arr[i]);
            cnt--;
        }
        if(n==1) {
            cout<<"YES"<<endl;
            continue;
        }
        bool ans=1;
        for(int i=2;i<=n;i++) if(arr[i]<arr[i-1]) ans=0;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}