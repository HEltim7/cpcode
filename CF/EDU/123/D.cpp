#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int mod=998244353;
const int N=2e5+10;

int row[N],col[N],rcnt,ccnt;

inline void add_row(int x){
    row[x]++;
    if(row[x]==1) rcnt++;
}

inline void add_col(int x){
    col[x]++;
    if(col[x]==1) ccnt++;
}

inline void del_row(int x){
    row[x]--;
    if(row[x]==0) rcnt--;
}

inline void del_col(int x){
    col[x]--;
    if(col[x]==0) ccnt--;
}

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,q;
        cin>>n>>m>>k>>q;
        vector<pair<int,int>> ins;
        while(q--){
            int x,y;
            cin>>x>>y;
            ins.push_back({x,y});
            add_row(x),add_col(y);
        }
        int res=0;
        for(auto [x,y]:ins){
            del_row(x),del_col(y);
            if((rcnt==n||col[y])&&(ccnt==m||row[x])) continue;
            else res++;
        }
        cout<<qpow(k,res)<<endl;
    }
    return 0;
}