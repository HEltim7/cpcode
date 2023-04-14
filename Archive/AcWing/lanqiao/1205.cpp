#include<iostream>
#include<cstring>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    bool isok[n*m+1];
    memset(isok,0,sizeof isok);
    for(int j=0;j<=m;j++){
        for(int i=0;i<=n&&(i*m+j*n<=n*m);i++){
            isok[i*m+j*n]=1;
        }
    }
    for(int i=n*m;i>=1;i--) if(!isok[i]) {
        cout<<i;
        return 0;
    }
}