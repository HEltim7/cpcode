#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
int arr[N],cnt[N];
LL sum[N];

constexpr int M=N;
int prime[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

vector<int> get_factor(int val) {
    vector<int> res;
    while(val>1) {
        int t=minp[val];
        res.push_back(t);
        while(minp[val]==t) val/=t;
    }
    return res;
}

void solve() {
    get_prime();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);

    LL ans=0;
    for(int i=1;i<=n;i++) {
        LL cur=1LL*i*(i-1)/2-i+1;
        auto &&vec=get_factor(arr[i]);
        for(int bit=1;bit<1<<vec.size();bit++) {
            int sign=__builtin_popcount(bit)&1?-1:1;
            int num=1;
            for(int j=0;j<vec.size();j++) if(bit>>j&1) num*=vec[j];
            LL res=1LL*i*cnt[num]-sum[num]-cnt[num];
            cur+=res*sign;
        }
        ans+=cur;

        for(int j=1;j*j<=arr[i];j++) 
            if(arr[i]%j==0) {
                cnt[j]++,sum[j]+=i;
                if(j*j!=arr[i]) cnt[arr[i]/j]++,sum[arr[i]/j]+=i;
            }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}