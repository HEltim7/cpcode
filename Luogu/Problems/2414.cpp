#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;

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

    void insert(string &s) {
        int root=0;
        for(auto x:s) {
            int c=x-start;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt++;
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
    
    int match(string &s) {
        int j=0,ans=0;
        for(auto x:s) {
            int c=x-start;
            j=tr[j].ch[c];
            //...
        }
        return ans;
    }

    int size() { return idx; }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz); }
};

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}