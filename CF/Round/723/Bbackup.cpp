#include<iostream>
using namespace std;

int test[10010];

int main(){
    std::ios::sync_with_stdio(0);
    std:cin.tie(0),std::cout.tie(0);
    int n=1000;
    int x;
    bool flag;
    // cin>>n;

    for(int i=1;i<=10000;i++) test[i]=i;
    int cnt=0;

    while(n--){
        flag=1;
        // cin>>x;
        x=test[++cnt];
        x%=1221;
        for(int i=0;i<=11&&x-i*111>=0;i++){
            int res=x-i*111;
            if(res%11==0){
                cout<<"["<<x<<"] YES 111:"<<i<<" 11:"<<res/11<<'\n';
                // cout<<"YES";
                flag=0;
                break;
            }
        }
        if(flag) cout<<"["<<x<<"] NO\n";
        // if(flag)cout<<"NO";
    }
    return 0;
}