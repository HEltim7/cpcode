#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int pre[N],suf[N];

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
        }
        last=node[pre].ch[c];
        node[last].cnt++;
        return node[last].len;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { node.reserve(sz),clear(); }
} pam(N);

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++) pre[i+1]=pam.extend(s[i]);
    reverse(s.begin(),s.end());
    pam.clear();
    for(int i=0;i<n;i++) suf[n-i]=pam.extend(s[i]);

    int ans=0;
    for(int i=1;i<=n;i++) if(pre[i]&&suf[i+1]) ans=max(ans,pre[i]+suf[i+1]);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}