#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
int n,x,y;
const int N=1e5+10;
typedef pair<int,int> PII;
PII pre[N];

bool check(int row,int col,int step){
    int dis=abs(x-row)+abs(y-col);
    if(dis>step||(dis&1)!=(step&1)) return 0;
    return 1;
}

bool fn(int len,int endx,int endy){
    for(int i=1;i<=n-len+1;i++){
        int j=i-1;
        auto [a,b]=pre[i+len-1];
        auto [c,d]=pre[j];
        int Y=a-c;
        int X=b-d;
        if(check(endx-X,endy-Y,len)) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string cmd;
    cin>>n;
    cin>>cmd;
    cin>>x>>y;
    if(check(0,0,n)==0){
        cout<<-1;
        return 0;
    }
    cmd=" "+cmd;
    for(int i=1;i<cmd.size();i++){
        char c=cmd[i];
        pre[i]=pre[i-1];
        if(c=='U') pre[i].first++;
        else if(c=='D') pre[i].first--;
        else if(c=='L') pre[i].second--;
        else pre[i].second++;
    }
    int row=pre[n].first;//y
    int col=pre[n].second;//x
    int l=0,r=n;
    while(l<r){
        int mid=l+r>>1;
        if(fn(mid,col,row)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}