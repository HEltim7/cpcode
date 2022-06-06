#include<iostream>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
typedef tuple<int,int,int> TIII;
const int N=50000+10,M=2e5+10,P=1000000+10;

TIII q[M];//query
int len;//length of block
int arr[N],ans[M],cnt[P];

inline int getid(int x){
    return x/len;
}

inline bool cmp(TIII &a,TIII &b){
    if(getid(get<0>(a))!=getid(get<0>(b)))
        return get<0>(a)<get<0>(b);
    return get<1>(a)<get<1>(b);
}

inline void add(int x,int &res){
    cnt[x]++;
    if(cnt[x]==1) res++;
}

inline void del(int x,int &res){
    cnt[x]--;
    if(cnt[x]==0) res--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        auto &[l,r,qid]=q[i];
        cin>>l>>r;
        qid=i;
    }
    len=max(1,(int)sqrt(n*1.*n/m));
    sort(q+1,q+1+m,cmp);

    for(int i=1,l=1,r=0,res=0;i<=m;i++){
        auto &[a,b,qid]=q[i];
        while(r<b) add(arr[++r],res);
        while(r>b) del(arr[r--],res);
        while(l<a) del(arr[l++],res);
        while(l>a) add(arr[--l],res);
        ans[qid]=res;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    return 0;
}