#include<iostream>

int main() {
    int n,T;
    std::cin>>n>>T;
    int ans=2;
    for(int i=1; i<=n; ++i) {
        int x;
        std::cin>>x;
        ans=std::max(ans, (x-1)/T+1);
    }
    std::cout<<ans;
}
