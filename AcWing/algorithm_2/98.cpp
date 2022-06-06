#include<iostream>
#include<cmath>
using namespace std;

#define x first
#define y second
#define endl '\n'

typedef pair<int,int> PII;
typedef long long LL;

PII cdq(LL id,LL n){
    if(n==0) return {1,1};
    LL len=1<<n-1;//区块边长
    LL chunk=len*len;
    LL block=id/chunk;
    PII res=cdq(id-block*chunk,n-1);
    if(block==0) return {res.y,res.x};
    else if(block==1) return {res.x,res.y+len};
    else if(block==2) return {res.x+len,res.y+len};
    return {len+1-res.y+len,len+1-res.x};
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        LL n,id1,id2;
        cin>>n>>id1>>id2;
        PII ans1=cdq(id1-1,n);//-1避免边界
        PII ans2=cdq(id2-1,n);
        cout<<(LL)(sqrt(pow((ans1.x-ans2.x),2)+pow((ans1.y-ans2.y),2))*10+0.5)<<endl;
    }
}