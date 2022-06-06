#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
const int N=1e6+10;
int A,n,mbit;
bool pass[N];
int qpow[]={0,10,100,1000,10000,100000,1000000,10000000};

struct NODE{
    int num,bit,step;
};

NODE q[N];

inline int getbit(int x){
    int res=0;
    while(x) res++,x/=10;
    return res;
}

int bfs(){
    int hh=0,tt=1;
    q[0]={n,mbit,0};
    while(hh!=tt){
        auto [x,bit,step]=q[hh++];
        if(hh==N) hh=0;
        if(x==1) return step;
        int y=x/A;
        if(y*A==x){
            int tbit=getbit(y);
            pass[y]=1;
            q[tt++]={y,tbit,step+1};
            if(tt==N) tt=0;
        }
        if(bit==1) continue;
        int b=x/qpow[bit-1];
        if((x-b*qpow[bit-1])*10<qpow[bit-1]) continue;
        y=(x-b*qpow[bit-1])*10+b;
        if(!pass[y]){
            pass[y]=1;
            q[tt++]={y,bit,step+1};
            if(tt==N) tt=0;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>A>>n;
    mbit=getbit(n);
    cout<<bfs();
    return 0;
}