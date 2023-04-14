#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=30;
int req[N];
int num[N],val[N],res[N],tmp[N];
int maxx;
int n,k,s;
bool bad[N];

void dfs(int deep,int last){
    if(deep>k){
        for(int i=0;i<n;i++) tmp[i]=res[i];
        sort(tmp,tmp+n,greater<int>());
        int t=s,ans=0;
        for(int i=0;i<n;i++){
            t+=tmp[i];
            if(t>=req[i]) ans++;
        }
        maxx=max(maxx,ans);
        return ;
    }
    for(int i=last;i<n;i++){
        if(bad[i]) continue;
        res[i]=max(res[i],val[i]);
        dfs(deep+1,i+1);
        res[i]=num[i];
    }
    dfs(deep+1,last+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>s;
    for(int i=0;i<n;i++) cin>>req[i];
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        num[i]=max(a,b);
        val[i]=max(c,d);
        if(val[i]<=num[i]) bad[i]=1;
        res[i]=num[i];
    }
    dfs(1,0);
    cout<<maxx;
    return 0;
}