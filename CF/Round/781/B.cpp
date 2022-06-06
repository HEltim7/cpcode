#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int cnt=1,tmp=1;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) tmp++;
            else tmp=1;
            cnt=max(cnt,tmp);
        }

        int ans=0;
        while(cnt<n){
            if(cnt*2<=n) ans+=1+cnt;
            else ans+=1+(n-cnt);
            cnt*=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}