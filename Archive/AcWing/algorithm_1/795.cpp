#include<iostream>
using namespace std;
typedef long long ll;

const int N=1e5+10;
ll num[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        num[i]+=num[i-1];
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<num[r]-num[l-1]<<'\n';
    }
    return 0;
}