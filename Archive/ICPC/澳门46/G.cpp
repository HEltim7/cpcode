#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MAX=1e12;
int arr[N*2],tmp[N],pos[N],nex[2][N];
LL dp[2][N];
int n,k;

void init(){
    set<int> st;
    for(int i=1;i<=n;i++) st.insert(i);
    st.insert(N);
    for(int i=1;i<n+k;i++){
        st.erase(arr[i]);
        if(i-k+1>0){
            nex[0][i-k+1]=*st.lower_bound(arr[i-k+1]);
            nex[1][(i-1)%n+1]=*st.lower_bound(arr[i]);
            st.insert(arr[i-k+1]);
        }
    }
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i],arr[i+n]=arr[i];
        pos[arr[i]]=i;
    }
    if(n==k){
        cout<<0<<endl;
        return ;
    }
    init();
    memset(dp[0],0x3f,sizeof (LL)*(n+1));
    memset(dp[1],0x3f,sizeof (LL)*(n+1));

    int t;
    if(pos[1]>=1&&pos[1]<=k){
        for(int i=1;i<=k;i++) tmp[i]=arr[i];
        sort(tmp+1,tmp+1+k);
        tmp[k+1]=N;
        for(int i=2;i<=k+1;i++)
            if(tmp[i]-tmp[i-1]>1){
                t=tmp[i-1]+1;
                break;
            }
    }
    else t=1; 
    
    dp[0][t]=min(abs(1-pos[t]),n-abs(1-pos[t]));
    dp[1][t]=min(abs(k-pos[t]),n-abs(k-pos[t]));
    
    LL ans=INF;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            if(dp[j][i]>MAX) continue;
            int l,r,v,p;
            if(j==0) l=pos[i],r=(pos[i]+k-1-1)%n+1,v=nex[0][l];
            else l=(pos[i]-k+1+n-1)%n+1,r=pos[i],v=nex[1][r];
            p=pos[v];
            
            if(v>n) ans=min(ans,dp[j][i]);
            else{
                dp[0][v]=min(dp[0][v],dp[j][i]+min(abs(l-p),n-abs(l-p)));
                dp[1][v]=min(dp[1][v],dp[j][i]+min(abs(r-p),n-abs(r-p)));
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}