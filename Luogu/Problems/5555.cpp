#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;

using PAM=struct PalindromeAutomaton {
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

    void build(string &s) { for(auto x:s) extend(x); }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { str.reserve(sz),node.reserve(sz),clear(); }
};

PAM pam[2]={PAM(N),PAM(N)};
auto &L=pam[0].node;
auto &R=pam[1].node;
int cnt[N];

void dfs(int l,int r) {
    cnt[L[l].len]++;
    for(int i=0;i<PAM::A;i++)
        if(L[l].ch[i]&&R[r].ch[i])
            dfs(L[l].ch[i],R[r].ch[i]);
}

void solve() {
    string s,t;
    cin>>s>>t>>s>>t;
    pam[0].build(s);
    pam[1].build(t);
    dfs(0,0);
    dfs(1,1);

    int n=min(s.size(),t.size());
    for(int i=n;i>=1;i--) {
        if(cnt[i]) {
            cout<<i<<' '<<cnt[i];
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}