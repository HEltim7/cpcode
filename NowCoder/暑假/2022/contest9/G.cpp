#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

#define endl '\n'
using LL=long long;
using ST=array<int, 6>;
constexpr int K=10;
int n,ans;

struct EerTree {
    const static int A=26;
    const static char B='a';
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

    void build(string &s) { for(auto x:s) extend(x); }

    EerTree() { init(); }
} pam[K];

void dfs(ST st) {
    ST tmp=st;
    for(int i=0;i<26;i++) {
        bool flag=1;
        for(int j=1;j<=n;j++) {
            if(!pam[j].node[st[j]].ch[i]) {
                flag=0;
                break;
            }
        }
        if(flag) {
            ans++;
            for(int j=1;j<=n;j++) tmp[j]=pam[j].node[st[j]].ch[i];
            dfs(tmp);
        }
    }
}

void solve() {
    string s;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s;
        pam[i].build(s);
    }
    dfs({0,0,0,0,0,0});
    dfs({1,1,1,1,1,1});
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}