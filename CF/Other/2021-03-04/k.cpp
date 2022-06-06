#include<iostream>
using namespace std;
const int N=1e3+10;
int num[N*2];
int tmp[N*2];
int  n;

bool check(){
    for(int i=1;i<n*2;i++){
        if(!tmp[i]+1==tmp[i+1]){
            break;
        }
        if(i==n-1) return 1;
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    for(int i=1;i<=n*2;i++) cin>>num[i];
    for(int i=1;i<=n*2;i++) tmp[i]=num[i];
    if(check()){
        cout<<0;
        return 0;
    }

    for(int i=1;i<n*2;i+=2){
        tmp[i]=num[i+1];
        tmp[i+1]=num[i];
    }
    if(check()){
        cout<<1;
        return 0;
    }

    for(int i=1;i<=n;i++){
        
    }
    
}