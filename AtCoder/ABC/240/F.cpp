#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;

inline LL cal(LL x,LL cnt){
    return (x+x*cnt)*cnt/2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        LL ans=0,sum=0,pre=0;
        for(int i=1;i<=n;i++){
            LL x,y;
            cin>>x>>y;
            if(i==1) ans=x;
            
            if(x>=0) ans=max(ans,sum+pre*y+cal(x,y));
            else if(pre>0){
                LL cnt=min(y,pre/abs(x));
                ans=max(ans,sum+pre*cnt+cal(x,cnt));
            }
            sum+=pre*y+cal(x,y);
            pre+=x*y;
        }
        cout<<ans<<endl;
    }
    return 0;
}