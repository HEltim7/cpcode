#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;
using LL=long long;
constexpr int N=1e6+10;
vector<int> adj[N];
int ind[N],dis[N];

struct PAM {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Node {
        int len,link;
        int cnt;
        int ch[A];
    };
    vector<Node> node;
    string str;
    int sz,last;
    
    int new_node(int len) {
        node.push_back({len});
        return ++sz;
    }

    void init() {
        sz=-1;
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
        for(int i=2;i<=sz;i++) {
            adj[i].push_back(node[i].link);
            ind[node[i].link]++;
            for(int c=0;c<A;c++) 
                if(node[i].ch[c]>=2) {
                    adj[node[i].ch[c]].push_back(i);
                    ind[i]++;
                }
        }
    }

    int solve() {
        int ans=0;
        queue<int> q;
        for(int i=2;i<=sz;i++) if(!ind[i]) q.push(i),dis[i]=1;
        while(q.size()) {
            int u=q.front();
            ans=max(ans,dis[u]);
            q.pop();
            for(int v:adj[u]) {
                dis[v]=max(dis[v],dis[u]+1);
                if(!--ind[v]&&v>=2) q.push(v);
            }
        }
        return ans;
    }

    PAM() { init(); }
};

void solve() {
    PAM pam;
    string s;
    cin>>s;
    int n=s.size();
    memset(ind,0,sizeof(int)*(n+5));
    memset(dis,0,sizeof(int)*(n+5));
    for(int i=0;i<=n+5;i++) adj[i].clear();

    pam.build(s);
    cout<<pam.solve()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}