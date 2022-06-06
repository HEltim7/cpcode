#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int candy[N];
int n,avg;
ll val[N];
ll sum,ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&candy[i]);
        sum+=candy[i];
    }
    avg=sum/n;
    for(int i=n;i>1;i--){
        val[i]=val[i+1]+avg-candy[i];
    }
    sort(val+1,val+1+n);
    for(int i=1;i<=n;i++) ans+=abs(val[i]-val[(i+1)/2]);
    cout<<ans;
    return 0;
}