#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
const int M=1e5+10;
int in,sum[M]={1},dif[M];
int cnt;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>in;
       for(int j=cnt;j>=0;j--){
           int now=dif[j]+in;
           if(!sum[now]) dif[++cnt]=now;
           sum[now]+=sum[dif[j]];
       }
       sort(dif,dif+cnt+1);
    }
    cout<<sum[m];
    return 0;
}