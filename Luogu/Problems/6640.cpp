#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,M=20;
int len[N],r[N];
int stl[M][N],str[M][N];

void get_st(int n) {
    for(int i=1;i<=n;i++) stl[0][i]=len[i],str[0][i]=r[i];
    for(int k=1;k<M;k++) {
        int t=1<<k;
        for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++) {
            stl[k][i]=max(stl[k-1][i],stl[k-1][mid]);
            str[k][i]=max(str[k-1][i],str[k-1][mid]);
        }
    }
}

int query_len(int l,int r) {
    int k=__lg(r-l+1);
    return max(stl[k][l],stl[k][r-(1<<k)+1]);
}

int query_r(int l,int r) {
    int k=__lg(r-l+1);
    return max(str[k][k],str[k][r-(1<<k)+1]);
}

struct SuffixAutomaton {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len;
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

    void match(string &s) {
        int idx=1,u=0;
        for(auto x:s) {
            int c=x-B;
            len[idx]=len[idx-1];
            while(u&&!edp[u].ch[c]) u=edp[u].link,len[idx]=edp[u].len;
            if(edp[u].ch[c]) u=edp[u].ch[c],len[idx]++;
            r[idx-len[idx]+1]=idx;
            idx++;
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    string s,t;
    int q;
    cin>>s>>t>>q;
    sam.build(t);
    sam.match(s);
    get_st(s.size());

    while(q--) {
        int l,r;
        cin>>l>>r;
        int res=0;
        res=max(res,min(r,query_r(1,l))-l+1);
        res=max(res,query_len(l,r));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}