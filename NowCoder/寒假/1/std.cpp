#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int sg(int x){
    if(x == 0) return 0;
    if(x<0) return -1;
    return 1;
}
int main(){
    freopen64("in.txt","r",stdin);
    freopen64("std.txt","w",stdout);
    int T; cin>>T; assert(T <= 1e4 && T > 0);
    int sumn = 0;
    while(T--){
        int n; scanf("%d", &n); sumn += n;
        assert(n <= 1e5 && n > 0);
        vector<int> f(n);
        fors(i,0,n) scanf("%d", &f[i]);
        vector<int> t1, t2;
        vector<int> cc;
        int cnt = 0;
        fors(i,1,n-1){
            if(f[i]>f[i-1] && f[i]>f[i+1]){
                int d = f[i]-max(f[i-1], f[i+1]);
                int up = max(f[i-1],f[i+1]) + d/2+1;
                t1.pb(up); cc.pb(up); 
            }
            else if(f[i] < min(f[i-1], f[i+1]) ) {
                int d = min(f[i-1], f[i+1])-f[i];
                int up = f[i]+(d+1)/2;
                t2.pb(up); cc.pb(up);
                cnt++;
            }else if(min(f[i-1], f[i+1]) < f[i] && max(f[i-1], f[i+1]) > f[i] ){
                int l = min(f[i-1], f[i+1]);
                int r = max(f[i-1], f[i+1]);
                int L = l+ (f[i]-l)/2 + 1;
                int R = f[i]+(r-f[i]+1)/2;
                if(L <= R) {t1.pb(L), t2.pb(R);}
            }
        }
        for(int x:t1) cc.pb(x); for(int x:t2) cc.pb(x);
        sort(all(cc)); cc.erase(unique(all(cc)), cc.end());
        vector<int> d(cc.size());
        for(int x:t1){
            // cout<<"x1:"<<x<<endl;
            int p = lower_bound(all(cc), x)-cc.begin(); d[p]++;
        }
        for(int x:t2){
            // cout<<"x2:"<<x<<endl;
            int p = lower_bound(all(cc), x)-cc.begin(); d[p]--;
        }
        int ans = cnt;
        fors(i,1,d.size()) d[i]+=d[i-1];
        for(int x:d) ans = min(ans, cnt+x);
        cout<<ans<<endl;
    }
    assert(sumn <= 1e6 && sumn > 0);
    return 0;
}