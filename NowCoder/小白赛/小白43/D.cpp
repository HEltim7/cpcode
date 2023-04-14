#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=5e5+10;
LL num[N];
LL n,ans,cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i],num[i]&=1;
        cnt++;
        if(num[i]) ans+=cnt*(n-i+1),cnt=0;
    }
    cout<<ans;
    return 0;
}