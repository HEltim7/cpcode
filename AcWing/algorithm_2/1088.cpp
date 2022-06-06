#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int N=2e6+10;
ll p[N],d[N];
ll prefix[N];
ll suffix[N];
ll que[N];
bool ans[N];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>d[i];
        p[i+n]=p[i],d[i+n]=d[i];
    }
    //顺时针
    for(int i=1;i<=2*n;i++) prefix[i]=prefix[i-1]+p[i]-d[i];
    int h=1,t=0;
    for(int i=1;i<2*n;i++){
        if(i-que[h]>=n) h++;
        while(prefix[i]<=prefix[que[t]]&&t>=h) t--;
        que[++t]=i;
        if(i>=n&&prefix[que[h]]>=prefix[i-n]) ans[i-n+1]=1;
    }
    //逆时针
    d[0]=d[n];
    for(int i=2*n;i>=2;i--) suffix[i]=suffix[i+1]+p[i]-d[i-1];
    h=2*n,t=2*n+1;
    for(int i=2*n;i>=2;i--){
        if(que[h]-i>=n) h--;
        while(suffix[i]<=suffix[que[t]]&&t<=h) t++;
        que[--t]=i;
        if(i<=n+1&&suffix[que[h]]>=suffix[i+n]) ans[i-1]=1;
    }
    
    for(int i=1;i<=n;i++) if(ans[i]) cout<<"TAK"<<endl; else cout<<"NIE"<<endl;
    return 0;
}