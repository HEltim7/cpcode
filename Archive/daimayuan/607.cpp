#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
int cnt[N];

int main() {
    // freopen64("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        cnt[in]++;
    }
    LL ans=0;
    for(int i=1;i<1e6;i++){
        if(cnt[i]==0) continue;
        for(int j=i+1;j<=1e6;j++){
            int t=1LL*j*j-1LL*i*i;
            if(t>1e6) break;
            ans+=1LL*cnt[i]*cnt[t];
        }
    cout<<ans;
    return 0;
}