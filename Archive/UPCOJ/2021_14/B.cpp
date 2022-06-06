#include<iostream>
using namespace std;

const int N=40;
bool like[N][N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int in;
            cin>>in;
            like[i][in]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        bool flag=1;
        for(int j=1;j<=n;j++) flag&=like[j][i];
        if(flag) ans++;
    }
    cout<<ans;
    return 0;
}