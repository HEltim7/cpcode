#include<iostream>
#include<cstring>
using namespace std;
int n,num[10];
bool able[10];

void dfs(int deep){
    if(deep>n){
        for(int x=1;x<=n;x++) cout<<num[x]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(able[i]){
            num[deep]=i;
            able[i]=0;
            dfs(deep+1);
            able[i]=1;
        }
    }
}

int main(){
    memset(able,1,sizeof able);
    cin>>n;
    dfs(1);
    return 0;
}