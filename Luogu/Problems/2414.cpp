#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;

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
    ACAM acam;
    string txt,s;
    cin>>txt;
    for(auto x:txt) 
        if(x=='B') s.pop_back();
        else s.push_back(x);
    txt.clear();
    for(auto x:s) {
        if(x=='P') acam.insert(txt),txt.clear();
        else txt.push_back(x);
    }
    acam.build();

    int m;
    cin>>m;
    vector<TIII> querys;
    vector<int> ans(m+1,0);
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        querys.emplace_back(a,b,i);
    }
    sort(querys.begin(),querys.end());
    int last=0;
    for(auto [a,b,id]:querys) {
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}