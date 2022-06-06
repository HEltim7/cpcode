#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'

const int N=110;
const int M=25010;
int coin[N];
bool mark[M];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        int maxx=0;
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>coin[i];
            maxx=max(maxx,coin[i]);
        }
        memset(mark,0,sizeof(bool)*(maxx+1));
        mark[0]=1;
        sort(coin+1,coin+1+n);
        for(int i=1;i<=n;i++){
            int c=coin[i];
            if(mark[c]) continue;
            for(int j=0;j<=maxx-coin[i];j++) if(mark[j]) mark[c+j]=1;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}