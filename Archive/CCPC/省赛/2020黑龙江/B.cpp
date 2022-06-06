#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
LL sum1,sum2,ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sum1=sum2=ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            LL in;
            cin>>in;
            sum1+=in;
            sum2+=in*in;
        }
        ans=sum2*(n-1)-(sum1*sum1-sum2);
        cout<<ans<<endl;
    }
    return 0;
}