#include<iostream>
#include<cmath>
using namespace std;
int sour[11],bitter[11];
int n,minn=1e9;

void dfs(int sums,int sumb,int deep,int sel){
    if(deep>n) return;
    if(deep==n&&sel) minn=min(abs(sums-sumb),minn);
    dfs(sums,sumb,deep+1,sel);
    dfs(sums*sour[deep+1],sumb+bitter[deep+1],deep+1,sel+1); 
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>sour[i]>>bitter[i];
    dfs(1,0,0,0);
    cout<<minn;
    return 0;
}