#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
int ans;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int n,l;
    int in;
    cin>>n>>l;
    while(n--){
        cin>>in;
        if(in<=l) ans++;
    }
    cout<<ans;
    return 0;
}