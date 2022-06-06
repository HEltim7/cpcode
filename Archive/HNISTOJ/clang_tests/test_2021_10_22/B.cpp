#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+10;
int ind[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    while(cin>>n>>m&&n){
        memset(ind,0,sizeof (int)*(n+1));
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            ind[b]++;
            ind[a]++;
        }
        bool res=1;
        for(int i=1;i<=n;i++) if(ind[i]==0||ind[i]%2) res=0;
        if(res) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}