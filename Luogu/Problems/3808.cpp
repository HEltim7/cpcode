#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
struct NODE {
    int cnt,next;
    int ch[26];
    bool passed;
    void init() {
        cnt=next=0;
        memset(ch,0,sizeof ch);
    }
} tr[N];
int idx;

int new_node() {
    tr[++idx].init();
    return idx;
}

void add(string &s) {
    int root=0;
    for(int j=0;j<s.length();j++) {
        int c=s[j]-'a';
        if(!tr[root].ch[c]) 
            tr[root].ch[c]=new_node();
        root=tr[root].ch[c];
    }
    tr[root].cnt++;
}

void build() {
    queue<int> q;
    for(int i=0;i<26;i++) 
        if(tr[0].ch[i]) q.push(tr[0].ch[i]);
    while(q.size()) {
        auto root=q.front();
        q.pop();
        for(int i=0;i<26;i++) {
            int &cur=tr[root].ch[i];
            int pre=tr[tr[root].next].ch[i];
            if(!cur) cur=pre;
            else {
                tr[cur].next=pre;
                q.push(cur);
            }
        }
    }
}

void solve() {
    tr[0].init();
    idx=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string in;
        cin>>in;
        add(in);
    }
    build();
    string s;
    cin>>s;
    int ans=0;
    for(int i=0,j=0;i<s.length();i++) {
        int c=s[i]-'a';
        j=tr[j].ch[c];
        int t=j;
        while(t&&!tr[t].passed) {
            tr[t].passed=1;
            ans+=tr[t].cnt;
            tr[t].cnt=0;
            t=tr[t].next;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}