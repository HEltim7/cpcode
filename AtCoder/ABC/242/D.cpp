#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
int num[N],n;

int dfs(LL x,LL times){
    if(times==0) return num[x];
    if(x==1) return (num[x]+times)%3;
    return (dfs((x+1)/2,times-1)+(x%2==0)+1)%3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    LL q,t,k;
    cin>>s>>q;
    n=s.size();
    for(int i=0;i<s.size();i++)
        if(s[i]=='A') num[i+1]=0;
        else if(s[i]=='B') num[i+1]=1;
        else num[i+1]=2;
    char c[]={'A','B','C'};
    while(q--){
        cin>>t>>k;
        int res=dfs(k,t);
        cout<<c[res]<<endl;
    }
    return 0;
}