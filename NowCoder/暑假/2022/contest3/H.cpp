#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PLL=pair<LL,LL>;
constexpr int N=1e5+10;
int val[N];

struct SegmentTree {

    struct Node {
        int l,r,len,mid;
        LL sum,rmax;
    } tr[N*4];

    void pushup(int u) {
        tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
        tr[u].rmax=max(tr[u<<1].rmax+tr[u<<1|1].sum,tr[u<<1|1].rmax);
    }

    PLL query(int u,int l,int r) {
        if(l>r) return {};
        if(tr[u].l>=l&&tr[u].r<=r) return {tr[u].sum,tr[u].rmax};
        if(tr[u].mid>=l&&tr[u].mid<r) {
            PLL res={},L=query(u<<1,l,r),R=query(u<<1|1,l,r);
            res.first=L.first+R.first;
            res.second=max(L.second+R.first,R.second);
            return res;
        }
        if(tr[u].mid>=l) return query(u<<1,l,r);
        return query(u<<1|1,l,r);
    }

    void build(int u,int l,int r) {
        tr[u]={l,r,r-l+1,l+r>>1};
        if(l==r) tr[u].sum=val[l],tr[u].rmax=max(0,val[l]);
        else {
            build(u<<1,l,tr[u].mid);
            build(u<<1|1,tr[u].mid+1,r);
            pushup(u);
        }
    }

} sgt;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
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

    LL solve(string &s) {
        int u=0,len=0,idx=1;
        LL ans=0;
        for(auto x:s) {
            int c=x-B;
            while(u&&!edp[u].ch[c]) u=edp[u].link,len=edp[u].len;
            if(edp[u].ch[c]) u=edp[u].ch[c],len++;
            ans=max(ans,sgt.query(1, idx-len+1, idx).second);
            idx++;
        }
        return ans;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    string s;
    int n,m,k;
    cin>>n>>m>>k>>s;
    for(int i=1;i<=m;i++) cin>>val[i];
    sam.build(s);
    sgt.build(1, 1, m);
    for(int i=1;i<=k;i++) {
        cin>>s;
        cout<<sam.solve(s)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}