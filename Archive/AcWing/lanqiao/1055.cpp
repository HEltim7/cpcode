#include<iostream>
using namespace std;
const int N=1e5+10;
int n,ans,now=-1;
int num[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        if(now==-1){
            if(num[i+1]-num[i]>0) now=num[i];
        }
        else{
            if(num[i+1]-num[i]<=0){
                ans+=num[i]-now;
                now=-1;
            }
        }
    }
    cout<<ans;
    return 0;
}