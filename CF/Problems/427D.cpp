#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=2e4+10;
bool s1[N],s2[N];
int mark1[N],mark2[N];
int ind[N];

struct GeneralSuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len;
        Arr ch;
    };
    vector<Endpos> edp;
    vector<Arr> tr;

    void init() {
        edp.clear(),edp.push_back({-1});
        tr.clear(),tr.push_back({});
    }

    int new_tr() { tr.push_back({}); return tr.size()-1; }
    int new_edp() { edp.push_back({}); return edp.size()-1; }

    int split(int p,int c,int len) {
        int q=edp[p].ch[c];
        if(edp[q].len==len) return q;
        else {
            int clone=new_edp();
            edp[clone]=edp[q];
            edp[clone].len=len;
            edp[q].link=clone;
            for(;p!=-1&&edp[p].ch[c]==q;p=edp[p].link)
                edp[p].ch[c]=clone;
            return clone;
        }
    }

    void extend(int &p,int &t,char x,int len) {
        int c=x-B;
        int last;
        if(tr[t][c]) last=edp[p].ch[c];
        else {
            tr[t][c]=new_tr();
            if(edp[p].ch[c]) last=split(p, c, len);
            else {
                int cur=last=new_edp();
                edp[cur].len=len;
                for(;p!=-1&&!edp[p].ch[c];p=edp[p].link)
                    edp[p].ch[c]=cur;
                if(p!=-1) edp[cur].link=split(p, c, edp[p].len+1);
            }
        }
        t=tr[t][c];
        p=last;
    }

    void extend(string &s,bool arr[]) {
        for(int p=0,t=0,i=0;i<s.size();i++) extend(p, t, s[i], i+1),arr[t]=1;
    }

    void dfs(int t,int u) {
        if(s1[t]) mark1[u]=1;
        if(s2[t]) mark2[u]=1;
        for(int c=0;c<A;c++) if(tr[t][c]) dfs(tr[t][c],edp[u].ch[c]);
    }

    int solve() {
        int res=N;
        dfs(0,0);
        queue<int> q;
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.push(i);
        while(q.size()) {
            int u=q.front();
            int v=edp[u].link;
            q.pop();
            if(mark1[u]==1&&mark2[u]==1) res=min(res,edp[v].len+1);
            mark1[v]+=mark1[u];
            mark2[v]+=mark2[u];
            if(v&&--ind[v]==0) q.push(v);
        }
        return res==N?-1:res;
    }

    int size() { return edp.size(); }
    void clear() { init(); }
    
    GeneralSuffixAutomaton() { init(); }
    GeneralSuffixAutomaton(int sz) { edp.reserve(sz),tr.reserve(sz),init(); }
} sam(N);

void solve() {
    string s;
    cin>>s;
    sam.extend(s,s1);
    cin>>s;
    sam.extend(s,s2);
    cout<<sam.solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}