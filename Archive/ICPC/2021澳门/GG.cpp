#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
#include<cstdio>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
const LL MAX=1e12;
int arr[N*2],tmp[N],pos[N],nex[2][N];
LL dp[2][N];
int n,k;

namespace IO {
const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)

inline int rd() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x * f;
}

char pbuf[1 << 20], *pp = pbuf;

inline void push(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}

inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) push(sta[--top] + '0');
}
}  // namespace IO


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
    n=IO::rd(),k=IO::rd();
    for(int i=1;i<=n;i++) {
        arr[i]=arr[i+n]=IO::rd();
        pos[arr[i]]=i;
    }
    if(n==k){
        printf("0\n");
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
    printf("%lld\n",ans);
}

int main() {
    int t;
    t=IO::rd();
    while(t--) solve();
    return 0;
}