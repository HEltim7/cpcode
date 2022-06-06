#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10;
LL mark[N],a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL n,k,x=0,sum=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=k;i++){
        if(mark[x]>0){
            LL step=i-mark[x],y=x;
            LL cnt=0;
            do
            {
                cnt+=a[x];
                x=(sum+cnt)%n;
            } while (y!=x);
            LL t=(k-i+1)/step;
            sum+=cnt*t;
            for(LL j=i+t*step;j<=k;j++){
                sum+=a[x];
                x=sum%n;
            }
            break;
        }
        mark[x]=i;
        sum+=a[x];
        x=sum%n;
    }
    cout<<sum;
    return 0;
}