#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cassert>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e4+10;
vector<int> adj[N];
bool mark[N];

#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

int bfs(int s,int e){
    memset(mark,0,sizeof mark);
    queue<pair<int,int>> q;
    q.push({s,0});
    mark[s]=1;
    while(q.size()){
        auto [t,step]=q.front();
        q.pop();
        if(t==e) return step;
        for(auto x:adj[t]){
            if(mark[x]) continue;
            mark[x]=1;
            q.push({x,step+1});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    for(int i=0;i<=9999;i++){
        int t=i;
        int num[5],bak[5];
        bak[4]=t%10,t/=10;
        bak[3]=t%10,t/=10;
        bak[2]=t%10,t/=10;
        bak[1]=t%10,t/=10;
        for(int len=1;len<=4;len++)
            for(int j=1;j+len-1<=4;j++)
                for(int z=0;z<=1;z++){
                    for(int y=1;y<=4;y++) num[y]=bak[y];
                    for(int k=j;k<=j+len-1;k++){
                        if(z) num[k]=(bak[k]+1+10)%10;
                        else num[k]=(bak[k]-1+10)%10;
                    }
                    int res=num[1]*1000+num[2]*100+num[3]*10+num[4];
                    adj[i].push_back(res);
                }
    }
    freopen64("in.txt","r",stdin);
    freopen64("std.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<bfs(a,b)<<endl;
    }
    return 0;
}