#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const long N=100010;
int len,lucky;
long num[N];
long long sum[N];

int main(){
    int z;
    cin>>z;
    for(int i=1;i<=z;i++){
        cin>>len>>lucky;
        for(int i=1;i<=len;i++){
            scanf("%d",&num[i]);
            sum[i]=(sum[i-1]+num[i])%lucky;
        }
        if(sum[len]%lucky==0){
            cout<<len<<endl;
            continue;
        }
        bool isok=0;
        for(int add=len-1;add>0&&isok==0;add--){
            for(int i=1;i<=len&&(i+add)<=len;i++){
                if((sum[i+add]-sum[i])%lucky==0){
                    isok=1;
                    cout<<add<<endl;
                    break;
                }
            }
        }
        if(isok==0){
            cout<<"-1"<<endl;
        }
    }
    return 0;
}