#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

//计算一段正区间
LL cal(int p,int r,int R){
    if(r<0) return 0;
    LL res=0;
    int k=(r+1)/p;
    r=r-k*p+1;
    res+=(R-0+1)*k;
    res+=min(r,R);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL p,l,r,L,R,ans=0;
    cin>>p>>l>>r>>L>>R;
    p=abs(p);
    L=max(L,-p+1),R=min(R,p-1);
    LL l1,l2,r1,r2;
    if(r>=0){
        ans=cal(p,r,R);
        if(l<0) ans+=
        else{
            r1=r,l1=0;
            r2=l-1,l2=0;
        }
    }
    else{
        if(l<0){

        }
    }

}