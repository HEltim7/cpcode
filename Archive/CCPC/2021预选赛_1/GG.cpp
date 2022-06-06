#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long LL;
typedef vector<int> VI;
LL n,a,b,c,d;
VI num;//这里不需要longlong

//需要先getnum再getmax,直接调用就行
void getnum(){
    LL t=n;
    num.clear();
    while(t) num.push_back(t%10),t/=10;
    reverse(num.begin(),num.end());
}

//输入n和g(x),返回最大值
LL getmax(LL gx){
    LL ans=0,res=0;
    for(int i=0;i<num.size();i++){
        int x=num[i];
        if(x!=0&&gx>=x-1){
            int bak=gx;
            LL tmp=res;
            tmp=tmp*10+x-1;
            bak=bak-x+1;
            for(int j=i+1;j<num.size();j++){
                if(bak>=9) tmp=tmp*10+9,bak-=9;
                else tmp=tmp*10+bak,bak=0;
            }
            if(bak==0) ans=max(ans,tmp);
        }
        if(gx>x) res=res*10+x,gx-=x;
        else if(gx<=x) res=res*10+gx,gx=0;
    }
    if(gx==0) ans=max(ans,res);
    return ans;
}

LL getmin(LL gx){
    VI res;
    while (gx){
        if(gx>=9){
            res.push_back(9);
            gx-=9;
        }
        else{
            res.push_back(gx);
            gx=0;
        }
    }
    LL ans=0;
    for(int i=res.size()-1;i>=0;i--) ans=ans*10+res[i];
    if(ans>n) return 0;
    return ans;
}

LL cal(LL gx,LL x){
    return (a*gx+b)*x*x+(c*gx*gx+d*gx)*x;
}

int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&n);
        getnum();
        LL ans=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=100;i++){
            LL xx=getmax(i);
            if(xx!=0) ans=min(ans,cal(i,xx));
            xx=getmin(i);
            if(xx!=0) ans=min(ans,cal(i,xx));
        }
        printf("%lld\n",ans);
    }
}