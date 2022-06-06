#include<iostream>
using namespace std;

int test[1000010];

int main(){
    std::ios::sync_with_stdio(0);
    std:cin.tie(0),std::cout.tie(0);
    int n=1000000;
    int x;
    bool flag;
    for(int i=1;i<=1000000;i++) test[i]=i;
    int cnt=0;
    // cin>>n;
    while(n--){
        flag=1;
        x=test[++cnt];
        cout<<n;
        for(int i=0;i<=x/111&&x-i*111>=0;i++){
            int res=x-i*111;
            if(res%11==0){
                cout<<"YES";
                flag=0;
                break;
            }
        }
        if(flag)cout<<"NO";
    }
    return 0;
}