#include<iostream>
using namespace std;

const int INF=0x3f3f3f3f;
const int N=1e3+10;
int row[N][N];
int maxx[N][N];
int minn[N][N];
int val[N][N];
int que[N];
int a,b,n,ans=INF;

void getmax(){
    for(int i=1;i<=a;i++){
        int hh=1,tt=0;
        for(int j=1;j<=b;j++){
            if(j-que[hh]>=n) hh++;
            while(val[i][j]>=val[i][que[tt]]&&tt>=hh) tt--;
            que[++tt]=j;
            row[i][j]=val[i][que[hh]];
        }
    }

    for(int i=1;i<=b;i++){
        int hh=1,tt=0;
        for(int j=1;j<=a;j++){
            if(j-que[hh]>=n) hh++;
            while(row[j][i]>=row[que[tt]][i]&&tt>=hh) tt--;
            que[++tt]=j;
            maxx[j][i]=row[que[hh]][i];
        }
    }
}

void getmin(){
    for(int i=1;i<=a;i++){
        int hh=1,tt=0;
        for(int j=1;j<=b;j++){
            if(j-que[hh]>=n) hh++;
            while(val[i][j]<=val[i][que[tt]]&&tt>=hh) tt--;
            que[++tt]=j;
            row[i][j]=val[i][que[hh]];
        }
    }

    for(int i=1;i<=b;i++){
        int hh=1,tt=0;
        for(int j=1;j<=a;j++){
            if(j-que[hh]>=n) hh++;
            while(row[j][i]<=row[que[tt]][i]&&tt>=hh) tt--;
            que[++tt]=j;
            minn[j][i]=row[que[hh]][i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a>>b>>n;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            cin>>val[i][j];

    getmax(),getmin();
    for(int i=n;i<=a;i++)
        for(int j=n;j<=b;j++)
            ans=min(ans,maxx[i][j]-minn[i][j]);
    cout<<ans;
    return 0;
}