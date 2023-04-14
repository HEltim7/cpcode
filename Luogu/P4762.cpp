#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int dp[N],pre[N],mp[1<<7];
vector<int> adj[N],stk;

struct PalindromeAutomaton {
    const static int A=4;
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

    void cal_pre(int u,int idx) {
        while(idx+1<stk.size()&&node[stk[idx+1]].len<=node[u].len/2) idx++;
        if(u) pre[u]=stk[idx];
        stk.push_back(u);
        for(int v:adj[u]) cal_pre(v, idx);
        stk.pop_back();
    }

    int bfs() {
        int ans=N,len=str.length()-1;
        queue<int> q;
        q.push(0);
        while(q.size()) {
            int u=q.front();
            q.pop();
            if(node[u].len==2) dp[u]=2;
            dp[u]=min(dp[u],dp[pre[u]]+node[u].len/2-node[pre[u]].len+1);
            ans=min(ans,len-node[u].len+dp[u]);
            
            for(int j=0;j<A;j++) {
                int v=node[u].ch[j];
                if(v) {
                    dp[v]=min(dp[v],dp[u]+1);
                    q.push(v);
                }
            }
        }
        return ans;
    }

    void build(string &s) {
        for(auto x:s) extend(x);
        for(int i=0;i<size();i++) adj[i].clear();
        for(int i=2;i<size();i++) {
            dp[i]=node[i].len;
            int &t=node[i].link;
            if(node[t].len&1) t=node[t].link;
            adj[t].push_back(i);
        }
        cal_pre(0, 0);
    }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { str.reserve(sz),node.reserve(sz),clear(); }
} pam(N);

void solve() {
    string s;
    cin>>s;
    for(auto &x:s) x=mp[x];
    pam.clear();
    pam.build(s);
    cout<<pam.bfs()<<endl;
}

int main() {
    mp['A']='a',mp['G']='b',mp['T']='c',mp['C']='d';
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}