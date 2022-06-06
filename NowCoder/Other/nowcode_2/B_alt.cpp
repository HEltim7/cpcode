#include<iostream>
#include<string>
using namespace std;

int main(){
    string in,trash;
    long same[200000]={0},tmp=0,j=0,ans=0;
    bool HeadIsA=1;
    getline(cin,trash);
    getline(cin,in);
    if(in[0]=='B') HeadIsA=0;
    for(int i=0;i<in.length();i++){
        tmp++;
        if(in[i]!=in[i+1]){
            same[++j]=tmp;
            tmp=0;
        }
    }
    
    if(HeadIsA){
        for(int i=1;i<=j;i+=2){
            tmp=same[i]+same[i+1]+same[i+2]+same[i+3];
            ans=max(ans,tmp);
        }
        if(j%2==1){
            ans=max(ans,same[j]+same[j-1]);
        }
    }
    else{
        for(int i=1;i<=j;i+=2){
            tmp=same[i]+same[i+1]+same[i+2]+same[i+3];
            ans=max(ans,tmp);
        }
        if(j%2==1){
            ans=max(ans,same[j]+same[j-1]);
        }
    }
    cout<<ans;
    return 0;
}