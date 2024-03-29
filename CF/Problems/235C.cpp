#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e6+10;
bool mark[N];

struct SuffixAutomaton {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len;
        int ind,siz;
        int ch[A];
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

    void get_siz(string &s) {
        for(int i=0,u=0;i<s.size();i++) u=edp[u].ch[s[i]-B],edp[u].siz++;
        queue<int> q;
        for(int i=1;i<size();i++) edp[edp[i].link].ind++;
        for(int i=1;i<size();i++) if(!edp[i].ind) q.push(i);
        while(q.size()) {
            int u=q.front();
            q.pop();
            edp[edp[u].link].siz+=edp[u].siz;
            if(edp[u].link&&!--edp[edp[u].link].ind) q.push(edp[u].link);
        }
    }

    int match(string &s) {
        vector<int> arr;
        int ans=0,u=0,len=0,n=s.size();
        s+=s;
        s.pop_back();
        for(auto x:s) {
            int c=x-B;
            while(u&&!edp[u].ch[c]) u=edp[u].link,len=edp[u].len;
            if(edp[u].ch[c]) u=edp[u].ch[c],len++;
            if(len==n) {
                if(!mark[u]) ans+=edp[u].siz,arr.push_back(u);
                mark[u]=1;
                if(edp[edp[u].link].len==len-1) u=edp[u].link;
                len--;
            }
        }
        for(auto x:arr) mark[x]=0;
        return ans;
    }

    void build(string &s) { for(auto x:s) extend(x); get_siz(s); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N);

void solve() {
    string s;
    cin>>s;
    sam.build(s);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s;
        cout<<sam.match(s)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}