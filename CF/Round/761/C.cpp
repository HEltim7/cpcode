#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=1e5+10;
int num[N];
bool filled[N];
bool used[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        memset(filled,0,sizeof(bool)*(n+1));
        memset(used,0,sizeof(bool)*(n+1));
        for(int i=1;i<=n;i++) cin>>num[i];
        sort(num+1,num+1+n);
        for(int i=1;i<=n;i++)
            if(num[i]<=n&&!filled[num[i]])
                filled[num[i]]=1,used[i]=1;
        bool flag=1;
        for(int i=1,j=1;i<=n&&j<=n;i++){
            if((filled[i])) continue;
            while(used[j]) j++;
            int maxx=(num[j]-1)>>1;
            if(maxx>=i){
                filled[i]=1;
                used[j]=1;
                ans++;
            }
            else{
                flag=0;
                break;
            }
        }
        if(flag) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}