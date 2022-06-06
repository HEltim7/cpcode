#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull data[40]={1,2 ,4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912},sum,in;

int main(){
    cin>>in;
    // data[0]=1;
    // for(int i=1;i<=29;i++){
    //     data[i]=data[i-1]*2;
    // }
    for(int i=0;i<=29;i++){
        for(int j=0;j<=29;j++){
            for(int k=0;k<=29;k++){
                sum=data[i]+data[j]+data[k];
                if(sum==in){
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}