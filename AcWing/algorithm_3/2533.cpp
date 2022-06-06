#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
typedef pair<int,int> PII;
PII cache[N];//fi=坐端点,se=右端点
struct QUERY{
    int l,r,id;
} q[N];
int cnt[N],num[N],pre[N];
int n,m,k;
LL ans[N];

inline void add(){

}

inline void del(){

}

bool cmp(QUERY a,QUERY b){
    if(a.l!=b.l) return a.l<b.l;
    else return a.r<b.r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        q[i]={a,b,i};
    }
    sort(q+1,q+1+n,cmp);

}