#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10;
int pos[N],cow[N];
bool mark[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k;
    bool flag=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>cow[i];
        if(cow[i]==1) flag=1;
    }
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        if(a==1){
            cout<<b;
            return 0;
        }
        mark[b]=1;
        pos[a]=b;
    }
    if(flag){
        int last=0;
        for(int i=1;i<=m;i++){
            if(!pos[cow[i]]){
                for(int j=last+1;j<=n;j++)
                    if(!mark[j]){
                        mark[j]=1;
                        pos[cow[i]]=j;
                        break;
                    }
            }
            last=pos[cow[i]];
        }
        cout<<pos[1];
    }
    else{
        for(int i=1;i<=m;i++){
            if(pos[cow[i]])
                for(int j=i-1;j>=1&&!pos[cow[j]];j--){
                    int idx=pos[cow[i]];
                    while(mark[idx]) idx--;
                    mark[idx]=1,pos[cow[j]]=idx;
                }
        }
        for(int i=1;i<=n;i++)
            if(!mark[i]){
                cout<<i;
                return 0;
            }
    }
    return 0;
}