#include<iostream>
using namespace std;
typedef long long ll;
int aim,n,coin[30];
ll way[10010]={1};

int main(){
    cin>>n>>aim;
    for(int i=1;i<=n;i++) scanf("%d",&coin[i]);
    for(int i=1;i<=n;i++){
        for(int j=coin[i];j<=aim;j++){
            way[j]+=way[j-coin[i]];
        }
    }
    cout<<way[aim];
    return 0;
}