#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10,INF=0x3f3f3f3f;
int date[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        date[0]=0,date[n+1]=d+1;
        for(int i=1;i<=n;i++) cin>>date[i];
        int min1=INF,min2=INF,maxlen=0,aimidx=0;
        for(int i=1;i<=n+1;i++) {
            int t=date[i]-date[i-1]-1;
            if(min1>=t){
                min2=min1;
                min1=t;
                aimidx=i;
            }
            else if(min2>t)
                min2=t;
            maxlen=max(maxlen,t);
        }
        if(min1==min2) cout<<min1<<endl;
        else {
            maxlen=max(maxlen,date[aimidx+1]-date[aimidx-1]-1);
            cout<<min(min2,(maxlen-1)/2)<<endl;
        }
    }
    return 0;
}