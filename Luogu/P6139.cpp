#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e6+10;

struct GeneralSuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len;
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

    int size() { return edp.size(); }
    
    void clear() {
        edp.clear(),edp.push_back({-1});
        tr.clear(),tr.push_back({});
    }
    
    LL solve() {
        LL res=0;
        for(int i=1;i<size();i++) 
            res+=edp[i].len-edp[edp[i].link].len;
        return res;
    }
    
    GeneralSuffixAutomaton(int sz=0) { edp.reserve(sz),tr.reserve(sz),clear(); }
} sam;

void solve() {
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++) cin>>s,sam.insert(s);
    cout<<sam.solve()<<endl<<sam.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}