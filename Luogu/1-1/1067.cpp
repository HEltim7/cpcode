#include<iostream>
using namespace std;
const int N=110;

int main(){
    int n,tmp;
    cin>>n>>tmp;
    if(n>=2){
        if(tmp>1) cout<<tmp<<"x^"<<n;
        else if(tmp==1) cout<<"x^"<<n;
        else if(tmp==-1) cout<<"-x^"<<n;
        else if(tmp<0) cout<<tmp<<"x^"<<n;
    }
    else if(n>=1){
        if(tmp>1) cout<<tmp<<"x";
        else if(tmp==1) cout<<"x";
        else if(tmp==-1) cout<<"-x";
        else if(tmp<0) cout<<tmp<<"x";
        cin>>tmp;
        if(tmp>0) cout<<'+'<<tmp;
        else if(tmp<0) cout<<tmp;
        return 0;
    }
    else{
        cout<<tmp;
        return 0;
    }
    for(int i=n-1;i>=1;i--){
        cin>>tmp;
        if(i==1){
            if(tmp>1) cout<<'+'<<tmp<<"x";
            else if(tmp==1) cout<<"+x";
            else if(tmp==-1) cout<<"-x";
            else if(tmp<0) cout<<tmp<<"x";
        }
        else{
            if(tmp>1) cout<<'+'<<tmp<<"x^"<<i;
            else if(tmp==1) cout<<"+x^"<<i;
            else if(tmp==-1) cout<<"-x^"<<i;
            else if(tmp<0) cout<<tmp<<"x^"<<i;
        }
    }
    cin>>tmp;
    if(tmp>0) cout<<'+'<<tmp;
    else if(tmp<0) cout<<tmp;
    return 0;
}