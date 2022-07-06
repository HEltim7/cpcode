#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
struct NODE {
    int id,next;
    int ch[26];
} tr[N];
int idx;
string str[N];

int new_node() {
    assert(idx<N);
    return ++idx;
}

void add(int id) {
    auto &s=str[id];
    int root=0;
    for(int j=0;j<s.length();j++) {
        int c=s[j]-'a';
        if(!tr[root].ch[c]) 
            tr[root].ch[c]=new_node();
        root=tr[root].ch[c];
    }
    tr[root].id=id;
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
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>str[i];
        add(i);
    }
    build();
    vector<int> state(1,0);
    string ans;
    for(int i=0,j=0;i<s.length();i++) {
        j=state.back();
        int c=s[i]-'a';
        j=tr[j].ch[c];
        ans.push_back(s[i]);
        state.push_back(j);
        if(tr[j].id) 
            for(auto x:str[tr[j].id])
                state.pop_back(),ans.pop_back();
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}