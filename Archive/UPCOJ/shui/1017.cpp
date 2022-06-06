#include<iostream>
#include<cmath>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N,m;
    cin>>N;
    while(N--){
        cin>>m;
        cout<<max(1,m-1)<<"\n";
    }
    return 0;
}