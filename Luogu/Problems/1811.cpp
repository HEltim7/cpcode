#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

struct SAM {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len;
        int next[A];
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
            if(!edp[p].next[c]) edp[p].next[c]=cur;
            else {
                int q=edp[p].next[c];
                if(edp[p].len+1==edp[q].len) edp[cur].link=q;
                else {
                    int clone=new_node();
                    edp[clone]=edp[q];
                    edp[clone].len=edp[p].len+1; 
                    edp[cur].link=edp[q].link=clone;
                    for(;p!=-1&&edp[p].next[c]==q;p=edp[p].link) 
                        edp[p].next[c]=clone;
                }
                break;
            }
            p=edp[p].link;
        }
    }

    void solve(string &s) {
        int cur=0,ans=0,len=0;
        for(auto x:s) {
            int c=x-B;
            while(cur&&!edp[cur].next[c]) cur=edp[cur].link,len=edp[cur].len;
            if(edp[cur].next[c]) cur=edp[cur].next[c],len++;
            ans=max(ans,len);
        }
        cout<<ans;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SAM() { edp.push_back({-1}); }
    SAM(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam;

void solve() {
    string s,t;
    cin>>s>>t;
    sam.build(s);
    sam.solve(t);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}