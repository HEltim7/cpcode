#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,mod=1e9+7;
LL dp[2][N],res[N];

void init(){
    dp[0][0]=res[0]=1;
    for(int i=1;i<N;i++){
        dp[1][i]=(dp[1][i-1]+dp[0][i-1])%mod;
        if(i>=2) dp[0][i]=(dp[1][i-2]+dp[0][i-2])%mod;
        res[i]=(res[i-1]+dp[0][i]+dp[1][i])%mod;
    }
}

inline int getlen(int x){
    int res=0;
    while(x) {
        res++;
        x>>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int n,p;
    cin>>n>>p;
    LL ans=0;
    set<int> st;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(p<=30&&in>=(1<<p)) continue;
        st.insert(in);
    }
    vector<int> del;
    for(auto x:st){
        int bak=x;
        while(x){
            int t=(x-1)>>1;
            if(t*2+1!=x) {
                t=x>>2;
                if(t*4!=x) break;
            }
            if(st.count(t)) {
                del.push_back(bak);
                break;
            }
            x=t;
        }
    }
    for(auto x:del) st.erase(x);

    for(auto x:st) ans=(ans+res[p-getlen(x)])%mod;
    cout<<ans;
    return 0;
}