#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e4+10;
int ind[N];

struct ACAM {
    const static int A=2;
    const static char start='0';
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
                    tr[cur].cnt+=tr[pre].cnt;
                    q.push(cur);
                }
            }
        }
    }
    
    string match() {
        int cnt=0,tot=tr.size();
        for(int i=0;i<tr.size();i++)
            if(!tr[0].cnt) {
                for(int j=0;j<A;j++) {
                    if(!tr[tr[i].ch[j]].cnt)
                        ind[tr[i].ch[j]]++;
                }
            }
            else tot--;
        queue<int> q;
        for(int i=0;i<tr.size();i++) if(!ind[i]) q.push(i),cnt++;
        while(q.size()) {
            int u=q.front();
            for(int i=0;i<A;i++) 
                if(!tr[tr[u].ch[i]].cnt)
                    if(--ind[tr[u].ch[i]]==0)
                        q.push(tr[u].ch[i]),cnt++;
            q.pop();
        }
        return cnt==tot?"NIE":"TAK";
    }

    int size() { return tr.size(); }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz); }
};

void solve() {
    int n;
    cin>>n;
    ACAM acam;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        acam.insert(s);
    }
    acam.build();
    cout<<acam.match();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}