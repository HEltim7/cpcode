#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    int n,in;
    cin>>n;
    bool data[4]={0,1,1,0};
    for(int i=1;i<=n;i++){
        cin>>in;
        if(data[in]==0){
            cout<<"NO";
            return 0;
        }
        else
        {
            if(data[1]==0){
                data[1]=1;
            }
            else
            {
                data[1]=0;
            }
            
            if(data[2]==0){
                data[2]=1;
            }
            else
            {
                data[2]=0;
            }
            
            if(data[3]==0){
                data[3]=1;
            }
            else
            {
                data[3]=0;
            }
            
            data[in]=1;
        }
        
    }
    cout<<"YES";
    return 0;
}