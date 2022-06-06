#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
int n;
int p,a;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int in;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>in;
        if(in>=80) p++,a++;
        else if(in>=60) p++;
    }
    if(p*1./n>0.95&&a*1./n>0.6) cout<<"Yes";
    else cout<<"No";
    return 0;
}