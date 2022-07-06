#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e3+10;
const LL mod=1e9+7;
LL dp[2][N][N];

struct ACAM {
    const static int A=10;
    const static char start='0';
    struct NODE {
        int cnt,next;
        int ch[A];
    };

    vector<NODE> tr;
    int idx=0;

    int new_node() {
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
    
    int match(string &s) {
        LL ans=0;
        int len=s.length();
        
        int c=s.front()-start;
        for(int j=1;j<c;j++) {
            int cur=tr[0].ch[j];
            if(!tr[cur].cnt) dp[0][1][cur]+=1;
        }
        if(!tr[tr[0].ch[c]].cnt) dp[1][1][tr[0].ch[c]]+=1;
        for(int i=2;i<=len;i++) {
            for(int j=1;j<=9;j++) {
                int cur=tr[0].ch[j];
                if(!tr[cur].cnt) dp[0][i][cur]+=1;
            }
        }

        for(int i=1;i<len;i++) {
            int c=s[i]-start;
            for(int j=0;j<=idx;j++) {
                for(int k=0;k<=9;k++) {
                    int cur=tr[j].ch[k];
                    if(!tr[cur].cnt) {
                        dp[0][i+1][cur]=(dp[0][i+1][cur]+dp[0][i][j])%mod;
                        if(k<c) dp[0][i+1][cur]=(dp[0][i+1][cur]+dp[1][i][j])%mod;
                        if(k==c) dp[1][i+1][cur]=(dp[1][i+1][cur]+dp[1][i][j])%mod;
                    }
                }
            }
        }
        for(int i=0;i<2;i++)
            for(int j=0;j<=idx;j++)
                ans=(ans+dp[i][len][j])%mod;
        return ans;
    }

    int size() { return idx; }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz); }
};

void solve() {
    string n;
    cin>>n;
    int m;
    cin>>m;
    ACAM acam;
    for(int i=1;i<=m;i++) {
        string in;
        cin>>in;
        acam.insert(in);
    }
    acam.build();
    cout<<acam.match(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}