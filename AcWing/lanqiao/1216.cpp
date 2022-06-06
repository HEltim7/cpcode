#include<iostream>
using namespace std;
int res,gai;

int main(){
    cin>>res;
    gai=res;
    while(gai>=3){
        res+=gai/3;
        gai=(gai-gai/3*3)+gai/3;
    }
    cout<<res;
    return 0;
}