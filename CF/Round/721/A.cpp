#include<iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int bit=0;
        while(n>1){
            n>>=1;
            bit++;
        }
        while(bit--) n<<=1;
        cout<<n-1<<'\n';
    }
    return 0;
}