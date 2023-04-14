#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=110;
int num[N];
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    sort(num+1,num+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=i,r=i,range=1;
        while(r<n){
            int idx=1;
            if(num[r+idx]-num[r]>range) break;
            while(r+idx<=n&&num[r+idx]-num[r]<=range) idx++;
            range++,r+=idx-1;
        }
        range=1;
        while(l>1){
            int idx=1;
            if(num[l]-num[l-idx]>range) break;
            while(l-idx>=1&&num[l]-num[l-idx]<=range) idx++;
            range++,l-=idx-1;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}