#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
struct NODE {
    int cnt,next;
    int ch[26];
} tr[N];
string str[N];
int idx,pos[N];
vector<int> bak;

int new_node() {
    assert(idx<N);
    return ++idx;
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
    pos[id]=root;
}

void build() {
    queue<int> q;
    for(int i=0;i<26;i++) 
        if(tr[0].ch[i]) 
            q.push(tr[0].ch[i]),bak.push_back(tr[0].ch[i]);
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
                bak.push_back(cur);
            }
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>str[i];
        add(i);
    }
    build();
    for(int k=1;k<=n;k++) {
        auto &s=str[k];
        for(int i=0,j=0;i<s.length();i++) {
            int c=s[i]-'a';
            j=tr[j].ch[c];
            tr[j].cnt++;
        }
    }
    while(bak.size()) {
        auto t=bak.back();
        bak.pop_back();
        tr[tr[t].next].cnt+=tr[t].cnt;
    }
    for(int i=1;i<=n;i++) cout<<tr[pos[i]].cnt<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}