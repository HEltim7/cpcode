#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e3+10;

struct node{
    double head;
    double tail;
} island[N];
int n,r,ans;

bool cmp(node a,node b){
    return a.tail<b.tail;
}

int main(){
    int x,y;
    double tmp;
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(y>r){
            cout<<-1;
            return 0;
        }
        tmp=sqrt(r*r-y*y);
        island[i].head=x-tmp;
        island[i].tail=x+tmp;
    }
    sort(island+1,island+1+n,cmp);
    double last=island[1].tail;
    ans=1;
    for(int i=2;i<=n;i++){
        if(island[i].head>last){
            last=island[i].tail;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}