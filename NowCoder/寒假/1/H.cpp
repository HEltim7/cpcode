#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;

LL cnt[N];
LL ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        cnt[in]++;
    }
    for(int i=0;i<=1000;i++){
        if(cnt[i]==0) continue;
        for(int j=i;j<=1000;j++){
            if(cnt[j]==0) continue;
            if(i!=j)
                ans+=cnt[i]*cnt[j]*(LL)abs(i+j-1000);
            else if(cnt[j]){
                LL tmp=(cnt[j]+1)*cnt[j]/2;
                ans+=tmp*(LL)abs(j+j-1000);
            }
        }
    }
    cout<<ans;
    return 0;
}