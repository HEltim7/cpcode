#include<iostream>
using namespace std;
const int N=1e5+10;
string name[N];
int dir[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>dir[i]>>name[i];
    int lr,len,now=1;
    for(int i=1;i<=m;i++){
        cin>>lr>>len;
        if(dir[now]==lr){
            now-=len;
            while(now<1) now+=n;
        }
        else{
            now+=len;
            while(now>n) now-=n;
        }
    }
    cout<<name[now];
    return 0;
}