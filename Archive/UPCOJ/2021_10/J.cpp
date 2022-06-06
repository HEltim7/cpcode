#include<iostream>
using namespace std;

typedef long long ll;
ll ans;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        ans+=abs(a-b);
    }
    cout<<ans;
    return 0;
}