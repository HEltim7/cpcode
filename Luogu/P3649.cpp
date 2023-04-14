#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

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

    void solve() {
        LL ans=0;
        for(int i=sz;i>=2;i--) {
            node[node[i].link].cnt+=node[i].cnt;
            ans=max(ans,1LL*node[i].len*node[i].cnt);
        }
        cout<<ans;
    }

    void build(string &s) { for(auto x:s) extend(x); }

    EerTree() { init(); }
};

void solve() {
    string s;
    cin>>s;
    EerTree pam;
    pam.build(s);
    pam.solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}