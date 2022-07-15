#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int pre[N],suf[N],tid;

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

    int insert(string &s,int val) {
        int root=0;
        for(auto x:s) {
            int c=x-start;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt+=val;
        return root;
    }

    void build(int arr[]) {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(tr[0].ch[i]) {
                q.push(tr[0].ch[i]);
                if(tr[0].ch[i]<=tid) 
                    arr[tr[0].ch[i]]=tr[tr[0].ch[i]].cnt;
            }
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
                    if(cur<=tid) arr[cur]=tr[cur].cnt;
                    q.push(cur);
                }
            }
        }
    }
    
    LL match() {
        LL ans=0;
        for(int i=1;i<tid;i++) ans+=1LL*pre[i]*suf[i+1];
        return ans;
    }

    int size() { return tr.size(); }
    void clear() { tr.clear();tr.resize(1);idx=0; }

    ACAM() { tr.resize(1); }
    ACAM(int sz) { tr.reserve(sz+1),tr.push_back({}); }
};

void solve() {
    ACAM acam;
    string t;
    vector<string> str;
    cin>>t;
    tid=acam.insert(t,0);
    str.push_back(t);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        acam.insert(s,1);
        str.push_back(s);
    }
    acam.build(pre);

    for(auto &x:str) 
        reverse(x.begin(), x.end());
    acam.clear();
    tid=acam.insert(str.front(),0);
    for(int i=1;i<=n;i++) acam.insert(str[i],1);
    acam.build(suf);
    reverse(suf+1, suf+1+tid);
    cout<<acam.match();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}