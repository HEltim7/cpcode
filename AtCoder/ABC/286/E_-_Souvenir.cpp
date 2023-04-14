#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=310,INF=0x3f3f3f3f;
int val[N],dis[N][N][N];
LL res[N][N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i],res[i][i]=val[i];
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++) {
            if(s[j]=='Y') dis[0][i][j+1]=1,res[i][j+1]=val[i]+val[j+1];
            else dis[0][i][j+1]=INF,res[i][j+1]=0;
        }
        dis[0][i][i]=0;
        res[i][i]=val[i];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                if(dis[k-1][i][k]+dis[k-1][k][j]<dis[k-1][i][j])
                    res[i][j]=res[i][k]+res[k][j]-val[k];
                else if(dis[k-1][i][k]+dis[k-1][k][j]==dis[k-1][i][j])
                    res[i][j]=max(res[i][j],res[i][k]+res[k][j]-val[k]);
                dis[k][i][j]=min(dis[k-1][i][j],dis[k-1][i][k]+dis[k-1][k][j]);
            }

    int Q,S,T;
    cin>>Q;
    while(Q--) {
        cin>>S>>T;
        if(dis[n][S][T]==INF) cout<<"Impossible"<<endl;
        else cout<<dis[n][S][T]<<' '<<res[S][T]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}