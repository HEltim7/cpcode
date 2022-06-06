#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e6+10;
LL dp[N];
int cnt[N];

void get(int x) {
    for(int i=1;i<=x/i;i++){
        if(x%i==0) {
            cnt[i]++;
            if(i!=x/i) cnt[x/i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        maxx=max(maxx,in);
        get(in);
    }
    for(int i=maxx;i>=1;i--){
        dp[i]=1LL*cnt[i]*i;
        for(int j=2;j*i<=maxx;j++) {
            dp[i]=max(dp[i],dp[j*i]+1LL*(cnt[i]-cnt[j*i])*i);
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}