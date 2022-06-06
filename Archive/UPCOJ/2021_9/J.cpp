#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=1e4+10;
ll num[N],ans;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>num[i];
    sort(num+1,num+n+1);
    for(int i=n;i>=1;i--){
        ans+=num[i]*i;
    }
    cout<<ans;
    return 0;
}