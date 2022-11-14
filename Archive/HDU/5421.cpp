#pragma GCC optimize("Ofast")
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL ans=0;

struct PalindromeAutomaton {
    const static int A=26;
    const static char B='a';
    struct Node {
        int len,link;
        int cnt;
        int ch[A];
    };
    vector<Node> node;
    deque<char> str;
    int last_l,last_r;

    int new_node(int len) {
        node.push_back({len});
        return node.size()-1;
    }
    
    void clear() {
        node.clear();
        last_l=last_r=0;
        str.clear();
        new_node(0);
        new_node(-1);
        node[0].link=1;
    }

    template<typename T> void extend(char x,int &last,T getfail) {
        int c=x-B;
        int pre=getfail(last);
        if(!node[pre].ch[c]) {
            int cur=new_node(node[pre].len+2);
            node[cur].link=node[getfail(node[pre].link)].ch[c];
            node[pre].ch[c]=cur;
            node[cur].cnt=node[node[cur].link].cnt+1;
        }
        last=node[pre].ch[c];
        if(node[last].len==str.size()) last_l=last_r=last;
        ans+=node[last].cnt;
    }

    void extend_l(char x) {
        str.push_front(x);
        extend(x, last_l, [&](int x) {
            int n=int(str.size())-1;
            while(node[x].len+1>n||str[node[x].len+1]!=str[0]) x=node[x].link;
            return x;
        });
    }

    void extend_r(char x) {
        str.push_back(x);
        extend(x, last_r, [&](int x) {
            int n=int(str.size())-1;
            while(n-node[x].len-1<0||str[n-node[x].len-1]!=str[n]) x=node[x].link;
            return x;
        });
    }

    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { node.reserve(sz),clear(); }
} pam(N);

void solve() {
    int n;
    while(cin>>n) {
        ans=0;
        pam.clear();
        while(n--) {
            int op;
            char in;
            cin>>op;
            if(op==1) cin>>in,pam.extend_l(in);
            else if(op==2) cin>>in,pam.extend_r(in);
            else if(op==3) cout<<pam.size()-2<<endl;
            else cout<<ans<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}