#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
int num[10010];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        cout<<++num[in]<<' ';
    }
    return 0;
}