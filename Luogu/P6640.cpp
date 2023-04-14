#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int len[N];

template<typename T=int> struct SparseTable {
    constexpr static int M=20;
    T st[M][N];

    void build(int n) {
        for(int i=1;i<=n;i++) st[0][i]=len[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=max(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return max(st[k][l],st[k][r-(1<<k)+1]);
    }
};
SparseTable<> st;

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
    st.build(s.size());

    while(q--) {
        int l,r;
        cin>>l>>r;
        int L=l-1,R=r;
        int res=0;
        
        while(L<R) {
            int mid=L+R+1>>1;
            if(len[mid]<=mid-l+1) R=mid-1;
            else L=mid;
        }
        res=max(L-l+1,st.query(L+1,r));
        cout<<res<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}