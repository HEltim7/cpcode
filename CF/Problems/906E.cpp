#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10,INF=1e9;
int dp[N],g[N],predp[N],preg[N];

struct PalindromeAutomaton {
    const static int A=26;
    const static char B='a';
    struct Node {
        int len,link;
        int ch[A];
        int dif,slink;
    };
    vector<Node> node;
    string str;
    int last;

    int new_node(int len) {
        node.push_back({len});
        return node.size()-1;
    }
    
    void clear() {
        node.clear();
        last=0;
        str="!";
        new_node(0);
        new_node(-1);
        node[0].link=1;
    }

    int getfail(int x) {
        while(str[str.size()-node[x].len-2]!=str.back()) x=node[x].link;
        return x;
    }

    void extend(char x) {
        str.push_back(x);
        int c=x-B;
        int pre=getfail(last);
        if(!node[pre].ch[c]) {
            int cur=new_node(node[pre].len+2);
            int lk=node[getfail(node[pre].link)].ch[c];
            node[cur].link=lk;
            node[pre].ch[c]=cur;
            node[cur].dif=node[cur].len-node[lk].len;
            node[cur].slink=node[cur].dif==node[lk].dif?node[lk].slink:lk;
        }
        last=node[pre].ch[c];
        
        int i=str.size()-1;
        for(int cur=last;cur>=2;cur=node[cur].slink) {
            auto &t=node[cur];
            int len=node[t.slink].len+t.dif;
            g[cur]=dp[i-len];
            preg[cur]=i-len;
            if(t.dif==node[t.link].dif) {
                if(g[t.link]<g[cur]) {
                    g[cur]=g[t.link];
                    preg[cur]=preg[t.link];
                }
            }
            if(i%2==0) {
                if(g[cur]+1<dp[i]) {
                    dp[i]=g[cur]+1;
                    predp[i]=preg[cur];
                }
                if(str[i]==str[i-1]&&dp[i-2]<dp[i]) {
                    dp[i]=dp[i-2];
                    predp[i]=i-2;
                }
            }
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { str.reserve(sz),node.reserve(sz),clear(); }
} pam(N);

void solve() {
    string x,y,z;
    cin>>x>>y;
    int n=x.size();
    for(int i=0;i<n;i++) z.push_back(x[i]),z.push_back(y[i]);
    n=z.size();
    
    for(int i=1;i<=n;i++) dp[i]=INF;
    pam.build(z);
    if(dp[z.length()]==INF) {
        cout<<-1<<endl;
        return;
    }
    cout<<dp[z.length()]<<endl;

    int cur=n;
    while(cur) {
        int last=predp[cur];
        if(cur-last>2) cout<<last/2+1<<' '<<cur/2<<endl;
        cur=last;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}