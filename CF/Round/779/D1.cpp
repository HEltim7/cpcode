#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1<<20;
int bit[2][20];
int n;
int arr[N];

void cntbit(int type){
    for(int i=1;i<=n;i++){
        int t=arr[i];
        for(int j=0;j<20;j++)
            if(t&(1<<j)) bit[type][j]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(bit,0,sizeof bit);
        int l,r;
        cin>>l>>r;
        int idx=0,cnt=l;
        n=r-l+1;
        for(int i=1;i<=n;i++) arr[i]=cnt++;
        cntbit(0);
        
        idx=0,cnt=l;
        for(int i=1;i<=n;i++) cin>>arr[i];
        cntbit(1);

        int ans=0;
        for(int i=0;i<20;i++) 
            if(bit[1][i]!=bit[0][i]) 
                ans+=(1<<i);
        cout<<ans<<endl;
    }
    return 0;
}