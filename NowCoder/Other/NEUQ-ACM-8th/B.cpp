#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int z;
    cin>>z;
    for(int i=1;i<=z;i++){
        int len,lucky;
        cin>>len>>lucky;
        long num[len+1];
        long long sum[len+1];
        sum[0]=0;
        for(int i=1;i<=len;i++){
            scanf("%d",&num[i]);
            sum[i]=sum[i-1]+num[i];
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