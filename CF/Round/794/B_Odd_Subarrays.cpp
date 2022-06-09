#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
const int N=1e5+10;
int tr[N],arr[N],n;

void add(int pos,int val) {
    while(pos<=n) tr[pos]+=val,pos+=lowbit(pos);
}

int query(int pos) {
    int res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

void solve() {
    cin>>n;
    memset(tr,0,sizeof (int)*(n+1));
    int ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1,j=1,sum=0;i<=n;i++) {
        add(arr[i],1);
        sum+=query(n)-query(arr[i]);
        if(sum) {
            while(j<=i) add(arr[j++],-1);
            ans++;
            sum=0;
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