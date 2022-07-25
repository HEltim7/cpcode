#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int ind[N];
LL res[N];

struct SAM {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len;
        int next[A];
    };
    vector<Endpos> am;
    int last=0;

    int new_node() {
        am.push_back({});
        return am.size()-1;
    }

    void extend(char x) {
        int c=x-B;
        int p=last;
        int cur=last=new_node();
        am[cur].len=am[p].len+1;
        while(p!=-1) {
            if(!am[p].next[c]) am[p].next[c]=cur;
            else {
                int q=am[p].next[c];
                if(am[p].len+1==am[q].len) am[cur].link=q;
                else {
                    int clone=new_node();
                    am[clone]=am[q];
                    am[clone].len=am[p].len+1; 
                    am[cur].link=am[q].link=clone;
                    for(;p!=-1&&am[p].next[c]==q;p=am[p].link) 
                        am[p].next[c]=clone;
                }
                break;
            }
            p=am[p].link;
        }
    }

    LL count() {
        for(int i=0;i<am.size();i++) 
            for(int j=0;j<A;j++) 
                if(am[i].next[j]) 
                    ind[am[i].next[j]]++;
        LL ans=-1;
        res[0]=1;
        queue<int> q;
        q.push(0);
        while(q.size()) {
            int u=q.front();
            q.pop();
            ans+=res[u];
            for(int i=0;i<A;i++) {
                int v=am[u].next[i];
                if(v) {
                    if(--ind[v]==0) q.push(v);
                    res[v]+=res[u];
                }
            }
        }
        return ans;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { am.clear(),am.push_back({-1}),last=0; }
    int size() { return am.size(); }
    
    SAM() { am.push_back({-1}); }
    SAM(int sz) { am.reserve(sz),am.push_back({-1}); }
} sam;

void solve() {
    string in;
    cin>>in>>in;
    sam.build(in);
    cout<<sam.count();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}