#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;

int dp[N],g[N];

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
            g[cur]=dp[i-(node[t.slink].len+t.dif)];
            if(t.dif==node[t.link].dif) g[cur]=min(g[cur],g[t.link]);
            dp[i]=min(dp[i],g[cur]+1);
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { str.reserve(sz),node.reserve(sz),clear(); }
} pam;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<=n;i++) dp[i]=1e9;
    pam.clear();
    pam.build(s);
    cout<<dp[s.length()]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}