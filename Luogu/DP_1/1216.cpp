#include<iostream>
using namespace std;
int num[1010],res[1010];

int main(){
    int deep,maxx=-1;
    cin>>deep;
    for(int i=1;i<=deep;i++){
        for(int j=1;j<=i;j++) cin>>num[j];
        for(int j=1;j<=i;j++) num[j]+=max(res[j],res[j-1]);
        for(int j=1;j<=i;j++) res[j]=num[j];
    }
    for(int i=1;i<=deep;i++) maxx=max(maxx,res[i]);
    cout<<maxx;
    return 0;
}