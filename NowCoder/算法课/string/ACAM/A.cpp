#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e6+10;
int id[N];

struct AhoCorasickAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Node {
        int link,cnt;
        int ch[A];
    };

    vector<Node> tr;
    vector<int> toporder;
    int sz=0;

    int insert(string &s) {
        int u=0;
        for(auto x:s) {
            int c=x-B;
            if(!tr[u].ch[c]) 
                tr[u].ch[c]=new_node();
            u=tr[u].ch[c];
        }
        // tr[u].cnt++;
        return u;
    }

    void build() {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(tr[0].ch[i]) {
                q.push(tr[0].ch[i]);

            }
        while(q.size()) {
            auto u=q.front();
            toporder.emplace_back(u);
            q.pop();
            for(int i=0;i<A;i++) {
                int &cur=tr[u].ch[i];
                int pre=tr[tr[u].link].ch[i];
                if(!cur) cur=pre;
                else {
                    // tr[cur].cnt+=tr[pre].cnt;
                    tr[cur].link=pre;
                    q.push(cur);
                }
            }
        }
    }

    void solve(string &s) {
        int u=0;
        for(char x:s) {
            int c=x-B;
            while(u&&!tr[u].ch[c]) u=tr[u].link;
            if(tr[u].ch[c]) u=tr[u].ch[c];
            tr[u].cnt++;
        }
        for(int i=1;i<=toporder.size();i++) {
            int u=toporder.end()[-i];
            tr[tr[u].link].cnt+=tr[u].cnt;
        }
    }

    int size() { return tr.size(); }
    int new_node() { tr.push_back({});return ++sz; }
    void clear() { tr.clear();tr.resize(1);sz=0; }

    AhoCorasickAutomaton(int size=1) {
        tr.reserve(size);
        tr.emplace_back();
    }
} acam(N);

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        id[i]=acam.insert(s);
    }
    string s;
    cin>>s;
    acam.build();
    acam.solve(s);
    for(int i=1;i<=n;i++) cout<<acam.tr[id[i]].cnt<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}