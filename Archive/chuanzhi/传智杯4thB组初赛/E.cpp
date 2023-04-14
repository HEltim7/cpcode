#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=1e6+10;

typedef pair<int,int> PII;
PII carrot[N];
int idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            int p,x,y;
            cin>>p;
            while(p--) cin>>x>>y,carrot[++idx]={x,y};
        }
        else{
            int x,minn,maxx,res=0;
            cin>>x>>minn>>maxx;
            for(int i=1;i<=idx;i++)
                if(carrot[i].first==x
                &&carrot[i].second>=minn
                &&carrot[i].second<=maxx)
                    res++;
            cout<<res<<endl;
        }
    }
    return 0;
}