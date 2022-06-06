#include<iostream>
#include<cstring>
using namespace std;

const int N=1e4+10;
int s[N],e[N];

int main(){
    memset(s,-1,sizeof s);
    memset(e,-1,sizeof e);
    int n,q,in;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>in;
        if(e[in]==-1) s[in]=i,e[in]=i;
        else e[in]=i;
    }
    while(q--){
        cin>>in;
        cout<<s[in]<<' '<<e[in]<<endl;
    }
    return 0;
}