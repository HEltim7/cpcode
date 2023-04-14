#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

#define endl '\n'
typedef long long LL;
double ans;

inline double cal(double x0,double y0,double x1,double y1){
    return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}

inline void update(double x0,double y0,double x,double y,double p,double q,double a,double b){
    if(p>=min(x,x+a)&&p<=max(x,x+a)&&
        q>=min(y,y+b)&&q<=max(y,y+b))
        ans=min(ans,cal(x0,y0,p,q));
    else ans=min({ans,cal(x0,y0,x,y),cal(x0,y0,x+a,y+b)});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    double x0,y0,x,y,xx,yy,k,beta,p,q;
    ans=cal(-1e9,-1e9,1e9,1e9);
    cin>>n;
    cin>>x>>y>>x0>>y0;
    for(int i=1;i<=n;i++){
        double a,b;
        cin>>a>>b;
        if(a==0) update(x0,y0,x,y,p=x,q=y0,a,b);
        else if(b==0) update(x0,y0,x,y,p=x0,q=y,a,b);
        else{
            k=b/a;
            beta=y-k*x;
            q=(k*k*y0+k*x0+beta)/(1+k*k);
            p=(y0-q)*k+x0;
            update(x0,y0,x,y,p,q,a,b);
        }
        x+=a,y+=b;
    }
    cout<<fixed<<setprecision(8)<<ans;
}