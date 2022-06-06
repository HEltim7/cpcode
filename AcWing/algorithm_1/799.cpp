#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+10;
int num[N];
bool mark[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    int ans=0;
    for(int i=1,j=0;i<=n;i++){
        if(mark[num[i]]){
            do mark[num[++j]]=0;
            while(num[j]!=num[i]);
        }
        mark[num[i]]=1;
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}