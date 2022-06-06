#include<iostream>
using namespace std;
int n;
int num[10];

void dfs(int num[],int idx){
    for(int i=1;i<=num[idx]/2;i++){
        if(i>=num[idx-1]){
            num[idx+1]=num[idx]-i;
            num[idx]=i;
            idx++;
            dfs(num,idx);
            idx--;
            num[idx]+=num[idx+1];
        }
    }
    if(idx==1) return;
    for(int i=1;i<idx;i++) cout<<num[i]<<'+';
    cout<<num[idx]<<endl;
    return;
}

int main(){
    cin>>n;
    int num[10]={0,n};
    dfs(num,1);
    return 0;
}