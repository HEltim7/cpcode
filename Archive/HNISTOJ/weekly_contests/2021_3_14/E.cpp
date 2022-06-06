#include<iostream>
using namespace std;
const int N=1e6+10;////////////////////////////////////////////////
const int M=1e7;
int m,n,cnt=1;
int luck[N];
struct node{
    int val;
    bool fuck;
} num[N];


int main(){
    cin>>m>>n;
    for(int i=1;i<=N;i++) num[i].val=i;
    luck[1]=2;
    while(luck[cnt]<n){
        for(int i=luck[cnt];num[i].val<=n;i+=luck[cnt]){
            num[i].fuck=1;
        }
        int i=1;
        for(int j=1;num[j].val<=n;j++){
            if(num[j].fuck==0){
                num[i++]=num[j];
            }
        }
        for(i;i<=n&&num[i].val!=M;i++) num[i].val=M;
        ++cnt;
        luck[cnt]=num[cnt].val;
    }
    luck[1]=1;
    int sum=0;
    for(int i=1;i<=cnt;i++){
        if(luck[i]>m&&luck[i]<n) sum++;
    }
    cout<<sum;
    return 0;
}