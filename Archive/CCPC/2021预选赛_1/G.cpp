#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
LL n;
VI num;//这里不需要longlong

//需要先getnum再getmax,直接调用就行
void getnum(){
    LL t=n-1;
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
