#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int man;
        cin>>man;
        cout<<man/4<<' '<<man/4*3<<endl;
    }
    return 0;
}