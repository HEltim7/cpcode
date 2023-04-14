#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=155,L=70;
struct NODE {
    int cnt,next;
    int ch[26];
    void init() {
        cnt=next=0;
        memset(ch,0,sizeof ch);
    }
} tr[N*L+10];
string str[N];
int idx,ans[N];

int new_node() {
    tr[++idx].init();
    return idx;
}

void add(int id) {
    string &s=str[id];
    int root=0;
    for(int j=0;j<s.length();j++) {
        int c=s[j]-'a';
        if(!tr[root].ch[c]) 
            tr[root].ch[c]=new_node();
        root=tr[root].ch[c];
    }
    tr[root].cnt=id;
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

void solve(int n) {
    memset(ans,0,sizeof ans);
    tr[0].init();
    idx=0;
    for(int i=1;i<=n;i++) {
        cin>>str[i];
        add(i);
    }
    build();
    string s;
    cin>>s;
    for(int i=0,j=0;i<s.length();i++) {
        int c=s[i]-'a';
        j=tr[j].ch[c];
        int t=j;
        while(t) {
            ans[tr[t].cnt]++;
            t=tr[t].next;
        }
    }
    int maxx=0;
    for(int i=1;i<=n;i++) maxx=max(maxx,ans[i]);
    cout<<maxx<<endl;
    for(int i=1;i<=n;i++) if(ans[i]==maxx) cout<<str[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    while(cin>>n&&n) solve(n);
    return 0;
}