#include<iostream>
using namespace std;

typedef long long ll;
ll ans,n,x,y;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    while(n--){
        cin>>x>>y;
        ans+=x*y;
    }
    cout<<ans;
    return 0;
}