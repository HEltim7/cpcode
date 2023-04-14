#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e3+10,mod=1e4+7;

int dp[N][N];

LL qpow(LL a,LL b) {
    LL res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

struct ACAM {
    const static int A=26;
    const static char start='A';
    struct NODE {
        int cnt,next;
        int ch[A];
    };

    vector<NODE> tr;
    int idx=0;

    int new_node() {
        assert(idx<N);
        tr.push_back({});
        return ++idx;
    }

    void insert(string &s) {
        int root=0;
        for(auto x:s) {
            int c=x-start;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt++;
    }

    void build() {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(tr[0].ch[i]) q.push(tr[0].ch[i]);
        while(q.size()) {
            auto root=q.front();
            q.pop();
            for(int i=0;i<A;i++) {
                int &cur=tr[root].ch[i];
                int pre=tr[tr[root].next].ch[i];
                if(!cur) cur=pre;
                else {
                    tr[cur].next=pre;
                    tr[cur].cnt+=tr[pre].cnt;
                    q.push(cur);
                }
            }
        }
    }
    
    int match(int m) {
        int ans=0;
        dp[0][0]=1;
        for(int i=0;i<m;i++) {
            int suf=qpow(26,m-(i+1));
            for(int j=0;j<=idx;j++) {
                for(int k=0;k<26;k++) {
                    int cur=tr[j].ch[k];
                    if(tr[cur].cnt) ans=(ans+dp[i][j]*suf%mod)%mod;
                    else dp[i+1][cur]=(dp[i+1][cur]+dp[i][j])%mod;
                }
            }
        }
        return ans;
    }

    int size() { return idx; }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz); }
};

void solve() {
    int n,m;
    cin>>n>>m;
    assert(m<N);
    ACAM acam;
    for(int i=1;i<=n;i++) {
        string in;
        cin>>in;
        acam.insert(in);
    }
    acam.build();
    cout<<acam.match(m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}