#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

struct GeneralSuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len,cnt;
        Arr ch;
    };
    vector<Arr> tr;
    vector<Endpos> edp;

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

    void insert(string &s) {
        for(int p=0,t=0,i=0;i<s.size();i++) extend(p, t, s[i], i+1);
    }

    vector<int> toporder;
    void toposort() {
        auto &q=toporder;
        q.clear();
        q.reserve(size());
        vector<int> ind(size());
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.push_back(i);
        for(int i=0;i<q.size();i++) {
            int u=q[i];
            int p=edp[u].link;
            if(p&&!--ind[p]) q.push_back(p);
        }
    }

    int find(int u,string &s) {
        for(char x:s) {
            int c=x-B;
            if(edp[u].ch[c]) u=edp[u].ch[c];
            else return -1;
        }
        return u;
    }

    void add(string &s) {
        int cnt=1;
        for(int u=find(0,s);u!=-1;) u=find(u,s),cnt++;
        cnt=max(cnt,2);
        string t=s;
        for(int i=2;i<=cnt;i++) s+=t;
        insert(s);
    }
    
    vector<int> q;
    vector<bool> mark;
    void init_count(string &s) {
        int u=0;
        for(char x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            edp[u].cnt++;
            q.emplace_back(u);
            mark[u]=1;
        }

        for(int i=0;i<q.size();i++) {
            int u=q[i];
            int p=edp[u].link;
            if(p==-1||mark[p]) continue;
            mark[p]=1;
            edp[p].cnt++;
            q.emplace_back(p);
        }
        for(int u:q) mark[u]=0;
        q.clear();
    }

    LL count(int n) {
        LL res=0;
        for(int i=1;i<size();i++) 
            if(edp[i].cnt==n) res+=edp[i].len-edp[edp[i].link].len;
        return res;
    }

    int size() { return edp.size(); }
    
    void clear() {
        edp.clear(),edp.push_back({-1});
        tr.clear(),tr.push_back({});
    }
    
    GeneralSuffixAutomaton(int sz=0) { edp.reserve(sz),tr.reserve(sz),clear(); }
} sam(1e6+10);

string minimize(const string &s) {
    int i=0,j=1,k=0,n=s.size();
    while(i<n&&j<n&&k<n) {
        if(s[(i+k)%n]==s[(j+k)%n]) k++;
        else {
            if(s[(i+k)%n]>s[(j+k)%n]) i=i+k+1;
            else j=j+k+1;
            if(i==j) i++;
            k=0;
        }
    }
    i=min(i,j);
    string res;
    for(int j=0;j<n;j++) res.push_back(s[(i+j)%n]);
    return res;
}

vector<int> zfunc(const string &s) {
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++) {
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    return z;
}

void solve() {
    int n;
    cin>>n;
    vector<string> s(n);
    for(auto &x:s) cin>>x;

    sort(s.begin(),s.end(),[&](string &x,string &y) {
        return x.size()>y.size();
    });

    auto get_rep=[&](string x) {
        x=minimize(x);
        auto &&z=zfunc(x);
        int mn=x.size();
        for(int i=1;i<z.size();i++) {
            if(x.size()%i==0&&z[i]==x.size()-i) {
                mn=i;
                break;
            }
        }
        string t=x.substr(0,mn);
        return t;
    };

    bool valid=false;
    string rep=get_rep(s[0]);
    for(int i=1;i<n;i++) {
        if(get_rep(s[i])!=rep) {
            valid=true;
            break;
        }
    }
    if(!valid) {
        cout<<-1<<endl;
        return;
    }

    for(auto &x:s) sam.add(x);
    sam.toposort();
    sam.mark.resize(sam.size());
    for(auto &x:s) sam.init_count(x);
    cout<<sam.count(n)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}