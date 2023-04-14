#include<iostream>
using namespace std;

int main(){
    long long res=1,n;
    cin>>n;
    for(int i=2;i<=n;i++){
        res*=i;
        if(res*(i+1)%10==0){
            while(res%10==0) res/=10;
            continue;
        }
        res%=10;
    }
    while(res%10==0) res/=10;
    cout<<res%10;
    return 0;
}