#include<iostream>
#include<algorithm>
using namespace std;

#define w first
#define h second
const int N=110;
typedef pair<int,int> PII;
PII book[N];
bool mark[N];
int dp[N];//从前i个物品选，宽度不超过j的最大宽度

int main(){
    int n,W,H;
    cin>>n>>W>>H;
    int maxh=0,sumw=0;
    for(int i=1;i<=n;i++){
        cin>>book[i].w>>book[i].h;
        maxh=max(maxh,book[i].h);
        sumw+=book[i].w;
    }

    if(maxh>H) cout<<"impossible";
    else if(maxh==H){
        if(sumw>W) cout<<"impossible";
        else cout<<"-1";
    }
    else if(sumw<=W) cout<<"-1";
    else if(maxh*2<=H){//书随便放
        for(int i=1;i<=n;i++)
            for(int j=W;j>=book[i].w;j--) 
                dp[j]=max(dp[j],dp[j-book[i].w]+book[i].w);
        
        if(sumw-dp[W]<=W) cout<<maxh;
        else cout<<"impossible";
    }
    else{//高的书放下层
        int uph=H-maxh;
        //只能放下面
        for(int i=1;i<=n;i++) if(book[i].h>uph) mark[i]=1;
        
        for(int i=1;i<=n;i++)
            for(int j=W;j>=book[i].w;j--)
                if(!mark[i])
                    dp[j]=max(dp[j],dp[j-book[i].w]+book[i].w);
        
        if(sumw-dp[W]<=W) cout<<maxh;
        else cout<<"impossible";
    }
    return 0;
}