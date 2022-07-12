#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=4e5+10;
int pre[N],suf[N]; //pre[i]表示s后缀与t前缀1->i匹配的次数,suf[i]表示s前缀与t后缀i->n匹配的次数
//ans=pre*suf+直接匹配

struct ACAM {
    const static int A=26;
    const static char start='a';
    struct NODE {
        int cnt,next;
        int ch[A];
    };

    vector<NODE> tr;
    int idx=0;

    int new_node() {
        tr.push_back({});
        return ++idx;
    }

    void insert(string &s,int val) {
        int root=0;
        for(auto x:s) {
            int c=x-start;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt+=val;
    }

    void build() {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(tr[0].ch[i]) q.push(tr[0].ch[i]);
        while(q.size()) {
            auto root=q.front();
            q.pop();
            for(int i=0;i<A;i++) {
                int &cur=tr[root].ch[i];
                int pre=tr[tr[root].next].ch[i];
                if(!cur) cur=pre;
                else {
                    tr[cur].next=pre;
                    // tr[cur].cnt+=tr[pre].cnt;
                    q.push(cur);
                }
            }
        }
    }
    
    LL match(string &s) {
        int j=0,ans=0;
        for(auto x:s) {
            int c=x-start;
            j=tr[j].ch[c];
            //...
        }
        return ans;
    }

    int size() { return tr.size(); }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz+1),tr.push_back({}); }
};

void solve() {
    ACAM acam;
    string t;
    cin>>t;
    acam.insert(t,1);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        acam.insert(s, 0);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}