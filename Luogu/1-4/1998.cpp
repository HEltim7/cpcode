#include<iostream>
using namespace std;

void dfs(int in){
    bool first=1;
    while(in){
        if(!first) cout<<'+';
        int i=0;
        while(1<<(i+1)<=in) i++;
        in-=1<<i;
        if(i==0) cout<<"2(0)";
        else if(i==1) cout<<2;
        else if(i==2) cout<<"2(2)";
        else{
            cout<<"2(";
            dfs(i);
            cout<<')';
        }
        first=0;
    }
}

int main(){
    int n;
    cin>>n;
    dfs(n);
    return 0;
}