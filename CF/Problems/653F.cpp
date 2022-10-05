#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;

vector<int> pos[N*2];
bool mark[N*2];

int count(int x,int l,int r) {
    x+=N;
    auto pre=lower_bound(pos[x].begin(),pos[x].end(),l);
    auto suf=upper_bound(pos[x].begin(),pos[x].end(),r);
    return suf-pre;
}

template<typename T=int> struct SparseTable {
    constexpr static int M=22;
    T arr[N],suf[N],st[M][N];

    void build(int n) {
        for(int i=n;i>=1;i--) suf[i]=arr[i]+suf[i+1];
        for(int i=1;i<=n;i++) pos[suf[i]+N].push_back(i);
        for(int i=1;i<=n;i++) st[0][i]=suf[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=min(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return min(st[k][l],st[k][r-(1<<k)+1]);
    }

    bool check(int l,int r) {
        return query(l, r)>=suf[r+1];
    }
};
SparseTable<> st;

struct SuffixAutomaton {
    constexpr static int A=2;
    constexpr static char B='0';
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
        LL ans=0;
        for(int i=0,u=0;i<s.size();i++) {
            int j=i+1;
            int c=s[i]-B;
            int v=u=edp[u].ch[c];
            for(int L=1,R;v&&!mark[v];v=edp[v].link,L=R+1) {
                mark[v]=1;
                R=j-edp[edp[v].link].len;
                int l=L,r=R;
                while(l<r) {
                    int mid=(l+r)/2;
                    if(st.check(mid,j)) r=mid;
                    else l=mid+1;
                }
                if(st.check(l,j)) ans+=count(st.suf[j+1], l, R);
            }
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
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++) {
        s[i]=s[i]=='('?'0':'1';
        st.arr[i+1]=s[i]=='0'?-1:1;
    }
    sam.build(s);
    st.build(n);
    cout<<sam.solve(s)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}