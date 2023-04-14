#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int res[N];

struct SuffixAutomaton {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len,cnt;
        int ch[A];
        int deg;
    };
    vector<Endpos> edp;
    int last=0;

    int new_node() {
        edp.push_back({});
        return edp.size()-1;
    }

    void extend(char x) {
        int c=x-B;
        int p=last;
        int cur=last=new_node();
        edp[cur].len=edp[p].len+1;
        while(p!=-1) {
            if(!edp[p].ch[c]) edp[p].ch[c]=cur;
            else {
                int q=edp[p].ch[c];
                if(edp[p].len+1==edp[q].len) edp[cur].link=q;
                else {
                    int clone=new_node();
                    edp[clone]=edp[q];
                    edp[clone].len=edp[p].len+1; 
                    edp[cur].link=edp[q].link=clone;
                    for(;p!=-1&&edp[p].ch[c]==q;p=edp[p].link) 
                        edp[p].ch[c]=clone;
                }
                break;
            }
            p=edp[p].link;
        }
    }

    void solve(string &s,int k) {
        memset(res, 0, sizeof(int)*(s.size()+1));
        clear();
        build(s);
        int u=0;
        bool flag=0;
        queue<int> q;
        for(int i=1;i<size();i++) edp[edp[i].link].deg++;
        for(int i=1;i<size();i++) if(!edp[i].deg) q.push(i);
        for(int i=0,u=0;i<s.size();i++) u=edp[u].ch[s[i]-B],edp[u].cnt++;
        while(q.size()) {
            int u=q.front();
            q.pop();
            edp[edp[u].link].cnt+=edp[u].cnt;
            if(edp[u].cnt==k) {
                flag=1;
                res[edp[u].len+1]--;
                res[edp[edp[u].link].len+1]++;
            }
            if(edp[u].link&&!--edp[edp[u].link].deg) q.push(edp[u].link);
        }
        int cnts=0,len=0;
        for(int i=1;i<s.size();i++) {
            res[i]+=res[i-1];
            if(res[i]>=cnts) cnts=res[i],len=i;
        }
        cout<<(flag?len:-1)<<endl;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam;

void solve() {
    string s;
    int k;
    cin>>s>>k;
    sam.solve(s,k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}