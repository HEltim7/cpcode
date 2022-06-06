#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=330;
struct NODE
{
    int val;
    int fa;
    int son;
}node[N];

void del(int id){
    int sonid=node[id].son;
    int faid=node[id].fa;
    node[sonid].fa=faid;
    node[faid].son=sonid;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++) node[i]={i,i-1,i+1};
    node[0].fa=-1;
    node[n].son=-1;
    int idx=0;
    bool dir=1;
    for(int i=1;i<n;i++){
        for(int i=1;i<=m;i++){
            if(dir==1&&node[idx].son==-1) dir=0;
            else if(dir==0&&node[idx].fa==0) dir=1;
            if(dir==1) idx=node[idx].son;
            else idx=node[idx].fa;
        }
        del(idx);
    }
    cout<<node[0].son;
    return 0;
}