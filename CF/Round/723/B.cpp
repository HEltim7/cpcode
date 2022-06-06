#include<iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    std:cin.tie(0),std::cout.tie(0);
    int n;
    int x;
    bool flag;
    cin>>n;
    while(n--){
        flag=1;
        cin>>x;
        if(x>10000){
            cout<<"YES\n";
            continue;
        }
        for(int i=0;i<=11&&x-i*111>=0;i++){
            int res=x-i*111;
            if(res%11==0){
                cout<<"YES\n";
                flag=0;
                break;
            }
        }
        if(flag) cout<<"NO\n";
    }
    return 0;
}