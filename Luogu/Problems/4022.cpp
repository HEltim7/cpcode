#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2.2e6+10;
int len[N];

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

    void extend(string &s) {
        for(int p=0,t=0,i=0;i<s.size();i++) extend(p, t, s[i], i+1);
    }

    void match(string &s) {
        for(int i=0,u=0,l=0;i<s.size();i++) {
            int c=s[i]-B;
            while(u&&!edp[u].ch[c]) u=edp[u].link,l=edp[u].len;
            if(edp[u].ch[c]) u=edp[u].ch[c],l++;
            len[i+1]=l;
        }
    }

    int size() { return edp.size(); }
    void clear() { init(); }
    
    GeneralSuffixAutomaton() { init(); }
    GeneralSuffixAutomaton(int sz) { edp.reserve(sz),tr.reserve(sz),init(); }
} sam(N);

bool check(int n,int k) {
    vector<int> res;
    res.reserve(n+1);
    res.push_back(0);
    for(int i=1,idx=0;i<=n;i++) {
        if(len[i]>=k) {
            int j=i-len[i];
            while(idx+1<res.size()&&idx<j) idx++;
            res.push_back(res[idx]+)
        }
    }
}

void solve() {
    int n,m;
    string s;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s;
        sam.extend(s);
    }
    while(m--) {
        cin>>s;
        sam.match(s);
        int l=0,r=s.length();
        while(l<r) {
            int mid=l+r>>1;
            if(check(s.length(),mid)) l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}