#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=n;i>=1;i--) cin>>num[i];
        num[0]=num[1];
        int cnt=0;
        for(int i=1;i<=n;){
            if(num[i]==num[i-1]) cnt++,i++;
            else{
                i+=cnt;
                if(i-1<=n) num[i-1]=num[0];
                cnt*=2;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}