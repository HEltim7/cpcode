#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int arr[N];
bool mark[N][10];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

inline int get(LL x){
    int res=0;
    for(int i=0;i<=1;i++,x>>=1)
        res+=(x&1)<<i;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        LL tx,ty;
        cin>>n>>tx>>ty;
        x=get(tx),y=get(ty);
        for(int i=0;i<=n;i++) memset(mark[i],0,sizeof mark[i]);
        debug(x,y);
        
        mark[0][x]=1;
        for(int i=1;i<=n;i++) {
            int in;
            cin>>in;
            in=get(in);
            for(int j=0;j<=7;j++)
                if(mark[i-1][j]){
                    mark[i][get(j+in)]=1;
                    mark[i][get(j^in)]=1;
                }
        }
        if(mark[n][y]) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}