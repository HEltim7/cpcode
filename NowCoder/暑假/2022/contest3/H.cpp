#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10,M=18;
LL val[N],pre[N],st[M][N];

void get_st(int n) {
    for(int i=1;i<=n;i++) st[0][i]=pre[i];
    for(int k=1;k<M;k++) {
        int len=1<<k;
        for(int i=1,mid=i+len/2,j=1+len-1;j<=n;i++,mid++,j++)
            st[k][i]=min(st[k-1][i],st[k-1][mid]);
    }
}

LL query(int l,int r) {
    int k=__lg(r-l);
    return min(st[k][l],st[k][r-(1<<k)+1]);
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

    LL match(string &s) {
        LL ans=0;
        int u=0,len=0,idx=1;
        for(auto x:s) {
            int c=x-B;
            while(u&&!edp[u].ch[c]) u=edp[u].link,len=edp[u].len;
            if(edp[u].ch[c]) u=edp[u].ch[c],len++;
            ans=max(ans,)
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    int n,k,m;
    string s;
    cin>>n>>k>>m>>s;
    sam.build(s);
    for(int i=1;i<=n;i++) cin>>val[i],pre[i]=val[i]+pre[i-1];
    while(k--) {
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