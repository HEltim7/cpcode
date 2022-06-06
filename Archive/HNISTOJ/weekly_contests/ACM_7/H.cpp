#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

bool iswin[220];
int main(){
    int a,b,n=0;
    iswin[1]=1;
    iswin[2]=0;
    iswin[4]=0;
    iswin[6]=0;
    for(int i=1;i<=210;i++){
        if(iswin[i]==1){
            iswin[i+1]=0;
            iswin[i+3]=0;
            iswin[i+9]=0;
        }
        else{
            iswin[i+1]=1;
            iswin[i+3]=1;
            iswin[i+9]=1;
        }
    }
    while(cin>>a&&a!=EOF){
        cin>>b;
        n=a+b;
        if(iswin[n]){
            cout<<"win"<<endl;
        }
        else
        {
            cout<<"lose"<<endl;
        }
    }
    return 0;
}