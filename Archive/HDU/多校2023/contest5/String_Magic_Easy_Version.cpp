#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N];
int cnt[N];

struct PalindromeAutomaton {
    const static int A=26;
    const static char B='a';
    struct Node {
        int len,link;
        int cnt;
        int ch[A];
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
            node[cur].link=node[getfail(node[pre].link)].ch[c];
            node[pre].ch[c]=cur;
        }
        last=node[pre].ch[c];
        node[last].cnt++;
    }

    void build(string &s) {
        for(auto x:s) extend(x);
        for(int i=2;i<size();i++)
            adj[node[i].link].push_back(i);
    }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { node.reserve(sz),clear(); }
} pam(N);

void init(int u) {
    for(int v:adj[u]) {
        init(v);
        pam.node[u].cnt+=pam.node[v].cnt;
    }
}

LL ans;
void dfs(int u) {
    int len=pam.node[u].len;
    if(len%2==0) ans+=cnt[len/2]?pam.node[u].cnt:0;
    cnt[len]++;
    for(int v:adj[u]) dfs(v);
    cnt[len]--;
}

void solve() {
    string s;
    cin>>s;
    ans=0;
    for(int i=0;i<=s.size()+5;i++) adj[i].clear();
    for(int i=0;i<=s.size()+5;i++) cnt[i]=0;
    pam.clear();
    pam.build(s);
    init(0);
    dfs(0);
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