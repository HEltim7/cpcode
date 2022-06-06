#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e7+10;
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

const int M=2e7+10;
bool st[M];
int primes[M],idx;

void init(int n) {
    st[1]=1;
    for(int i=2;i<=n;i++) {
        if(!st[i]) primes[idx++]=i;
        for(int j=0;primes[j]<=n/i;j++) {
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
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
    init(maxx);
    for(int i=maxx;i>=1;i--){
        dp[i]=1LL*cnt[i]*i;
        for(int j=0;primes[j]*i<=maxx&&j<idx;j++){
            int t=primes[j];
            dp[i]=max(dp[i],dp[t*i]+1LL*(cnt[i]-cnt[t*i])*i);
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}