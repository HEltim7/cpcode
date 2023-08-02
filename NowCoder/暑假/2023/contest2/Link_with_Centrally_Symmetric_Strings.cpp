#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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

constexpr int N=2e6+10,INF=0x3f3f3f3f;
int dp[N],g[N],mp[1<<7];
char ch[10]={'b','q','d','p','n','u','o','s','x','z'};

struct PalindromeAutomaton {
    constexpr static int A=10;
    constexpr static char B=0;
    struct Node {
        int len,link;
        int ch[A];
        int dif,slink;
    };
    vector<Node> node;
    string str;
    int last;

    int new_node(int len) {
        node.push_back({len});
        return node.size()-1;
    }
    
    void clear() {
        node.clear();
        last=0;
        str="!";
        new_node(0);
        new_node(-1);
        node[0].link=1;
    }

    int getfail(int x) {
        while(str[str.size()-node[x].len-2]!=str.back()) x=node[x].link;
        return x;
    }

    void extend(char x) {
        str.push_back(x);
        int c=x-B;
        int pre=getfail(last);
        if(!node[pre].ch[c]) {
            int cur=new_node(node[pre].len+2);
            int lk=node[getfail(node[pre].link)].ch[c];
            node[cur].link=lk;
            node[pre].ch[c]=cur;
            node[cur].dif=node[cur].len-node[lk].len;
            node[cur].slink=node[cur].dif==node[lk].dif?node[lk].slink:lk;
        }
        last=node[pre].ch[c];
        
        int i=str.size()-1;
        for(int cur=last;cur>=2;cur=node[cur].slink) {
            auto &t=node[cur];
            g[cur]=dp[i-(node[t.slink].len+t.dif)];
            if(t.dif==node[t.link].dif) g[cur]=min(g[cur],g[t.link]);
            if(node[cur].len%2==0) dp[i]=min(dp[i],g[cur]+1);
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { str.reserve(sz),node.reserve(sz),clear(); }
} pam(N);

void solve() {
    string s,t;
    cin>>s;
    t.reserve(s.size()*2);
    vector<int> tot(10);
    for(char x:s) {
        int id=mp[x];
        tot[id]++;
        if(ch[id]!=x) {
            cout<<"No"<<endl;
            return;
        }
        t.push_back(id);
        if(id<=5) t.push_back(((id&1)?id-1:id+1));
        else t.push_back(id);
    }
    if(tot[0]!=tot[1]||tot[2]!=tot[3]||tot[4]!=tot[5]) {
        cout<<"No"<<endl;
        return;
    }

    int n=t.size();
    memset(dp+1,0x3f,sizeof(int)*(n+1));
    pam.clear();
    pam.build(t);

    cout<<(dp[n]<INF?"Yes":"No")<<endl;
}

int main() {
    mp['b']=0,mp['q']=1,mp['d']=2,mp['p']=3,mp['n']=4,mp['u']=5;
    mp['o']=6,mp['s']=7,mp['x']=8,mp['z']=9;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}