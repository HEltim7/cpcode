#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;
int dep[N];

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

    int extend(char x) {
        str.push_back(x);
        int c=x-B;
        int pre=getfail(last);
        if(!node[pre].ch[c]) {
            int cur=new_node(node[pre].len+2);
            node[cur].link=node[getfail(node[pre].link)].ch[c];
            node[pre].ch[c]=cur;
            dep[cur]=dep[node[cur].link]+1;
        }
        last=node[pre].ch[c];
        node[last].cnt++;
        return dep[last];
    }

    void build(string &s) { for(auto x:s) extend(x); }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { node.reserve(sz),clear(); }
} pam(N);

void solve() {
    string s;
    cin>>s;
    int lastans=0;
    for(auto x:s) {
        char cur=(x-97+lastans)%26+97;
        lastans=pam.extend(cur);
        cout<<lastans<<' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}