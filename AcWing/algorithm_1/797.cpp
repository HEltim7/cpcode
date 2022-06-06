#include<iostream>
using namespace std;

typedef long long ll;
const int N=1e5+10;
ll num[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,l,r,c=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        num[i]-=c;
        cin>>c;
        num[i]+=c;
    }
    for(int i=1;i<=m;i++){
        cin>>l>>r>>c;
        num[l]+=c;
        num[r+1]-=c;
    }
    for(int i=1;i<=n;i++) num[i]+=num[i-1];
    for(int i=1;i<=n;i++) cout<<num[i]<<' ';
    return 0;
}