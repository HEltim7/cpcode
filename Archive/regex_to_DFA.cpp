/**
regex->DFA
by HEltim7
*/

#include <map>
#include <set>
#include <array>
#include <queue>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

string add_dot(string &s) {
    auto check=[](char x) {
        return x>='a'&&x<='z';
    };
    string res;
    for(auto r:s) {
        if(res.size()) {
            char l=res.back();
            if((check(l)||l==')'||l=='*')&&(check(r)||r=='('))
                res.push_back('.');
        }
        res.push_back(r);
    }
    return res;
}

string shunting_yard(string &s) {
    auto is_ident=[](char x) {
        return x>='a'&&x<='z';
    };

    auto is_operator=[](char x) {
        return x=='|'||x=='*'||x=='.';
    };

    auto left_assoc=[](char x) {
        return x=='|'||x=='*'||x=='.';
    };

    auto priority=[](char x) {
        if(x=='*') return 1;
        if(x=='.') return 2;
        if(x=='|') return 3;
        return 4;
    };

    s=add_dot(s);
    string res,stk;
    for(auto x:s) {
        if(is_ident(x)) res.push_back(x);
        else if(is_operator(x)) {
            while(stk.size()&&is_operator(stk.back())) {
                char l=stk.back();
                if (
                    left_assoc(x)&&priority(x)>=priority(l)||
                    !left_assoc(x)&&priority(x)>priority(l)
                ) stk.pop_back(),res.push_back(l);
                else break;
            }
            stk.push_back(x);
        }
        else if(x=='(') stk.push_back(x);
        else if(x==')') {
            while(stk.size()&&stk.back()!='(')
                res.push_back(stk.back()),stk.pop_back();
            assert(stk.back()=='(');
            stk.pop_back();
        }
    }

    while(stk.size()) {
        assert(stk.back()!='('&&stk.back()!=')');
        res.push_back(stk.back());
        stk.pop_back();
    }
    return res;
}

using FA = struct FiniteAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Node {
        array<vector<int>,A> ch;
        vector<int> empty;
        bool accept;
        auto &operator[](int idx) { return ch[idx]; }
    };
    vector<Node> node;
    int S;

    int new_node() {
        node.push_back({});
        return node.size()-1;
    }
    
    // build FA from regex
    void build(const string &s) {
        new_node();
        constexpr char flag='$';
        string stk;
        vector<pair<int,int>> res;
        for(auto x:s) {
            if(x>='a'&&x<='z') stk.push_back(x),res.push_back({});
            else if(x=='*') {
                assert(stk.size());
                auto cur=stk.back();
                stk.pop_back();
                auto [s,t]=res.back();
                res.pop_back();
                if(cur==flag) {
                    node[s].empty.push_back(t);
                    node[t].empty.push_back(s);
                }
                else {
                    int u=new_node();
                    int c=cur-B;
                    node[u][c].push_back(u);
                    s=t=u;
                }
                stk.push_back(flag);
                res.push_back({s,t});
            }
            else {
                assert(stk.size()>=2);
                auto r=stk.back();stk.pop_back();
                auto l=stk.back();stk.pop_back();
                auto [sr,tr]=res.back();res.pop_back();
                auto [sl,tl]=res.back();res.pop_back();

                if(l!=flag) sl=new_node(),tl=new_node(),node[sl][l-B].push_back(tl);
                if(r!=flag) sr=new_node(),tr=new_node(),node[sr][r-B].push_back(tr);

                if(x=='.') {
                    node[tl].empty.push_back(sr);
                    stk.push_back(flag);
                    res.push_back({sl,tr});
                }
                else {
                    int s=new_node(),t=new_node();
                    node[s].empty.push_back(sl);
                    node[s].empty.push_back(sr);
                    node[tl].empty.push_back(t);
                    node[tr].empty.push_back(t);
                    stk.push_back(flag);
                    res.push_back({s,t});
                }
            }
        }
        assert(res.size()==1);
        auto [l,r]=res.back();
        S=l;
        node[r].accept=1;
    }

    int size() { return node.size(); }
    void clear() { node.clear(); }

    FiniteAutomaton() {}
    FiniteAutomaton(const string &s) { build(s); }
};

using DFA = struct DeterministicFiniteAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Subset = set<int>;
    struct Node {
        array<int,A> ch;
        bool accept;
        auto &operator[](int idx) { return ch[idx]; }
        friend bool operator<(const Node &l,const Node &r) {
            if(l.accept!=r.accept) return l.accept<r.accept;
            return l.ch<r.ch;
        }
    };
    vector<Node> node;
    int S=1;

    int new_node() {
        node.push_back({});
        return node.size()-1;
    }

    // build DFA from NFA
    void build(const FA &fa) {
        const auto &fan=fa.node;
        auto closure=[&](const Subset &s) {
            queue<int> q;
            for(int x:s) q.push(x);
            Subset res=s;
            while(q.size()) {
                int u=q.front();
                for(int v:fan[u].empty)
                    if(!res.count(v)) 
                        res.insert(v),q.push(v);
                q.pop();
            }
            return res;
        };

        auto move=[&](const Subset &s,int c) {
            Subset res;
            for(int u:s)
                for(int v:fan[u].ch[c])
                    res.insert(v);
            return res;
        };
        
        Subset st=closure({fa.S});
        map<Subset,int> id;
        new_node();
        id[st]=new_node();
        queue<Subset> q;
        q.push(st);
        
        while(q.size()) {
            Subset cur=q.front();
            int curid=id[cur];
            q.pop();
            for(int c=0;c<A;c++) {
                Subset t=closure(move(cur,c));
                if(t.size()) {
                    if(!id.count(t)) {
                        node[curid][c]=id[t]=new_node();
                        q.push(t);
                    }
                    else node[curid][c]=id[t];
                }
            }
        }

        for(auto [st,i]:id) 
            for(int u:st) 
                node[i].accept|=fan[u].accept;
    }

    // remove useless nodes
    void trim() {
        vector<bool> markpre(size()),marksuf(size());
        vector<int> id(size());
        vector<vector<int>> pre(size());
        queue<int> q;
        q.push(S);
        markpre[S]=1;

        while(q.size()) {
            int u=q.front();
            for(int v:node[u].ch)
                if(v) {
                    if(!markpre[v]) markpre[v]=1,q.push(v);
                    pre[v].push_back(u);
                }
            q.pop();
        }
        
        for(int i=1;i<size();i++)
            if(node[i].accept) q.push(i),marksuf[i]=1;
        
        while(q.size()) {
            int u=q.front();
            for(int v:pre[u])
                if(!marksuf[v]) marksuf[v]=1,q.push(v);
            q.pop();
        }

        vector<Node> tmp(1);
        for(int i=1,idx=1;i<size();i++)
            if(markpre[i]&marksuf[i])
                id[i]=idx++,tmp.push_back(node[i]);
        for(auto &x:tmp) for(auto &y:x.ch) if(y) y=id[y];
        node=tmp;
    }

    // minimize DFA
    void minimize() {
        trim();
        int idx=0;
        vector<int> id(size());
        vector<Subset> st;
        Subset end,nonend;
        for(int i=S;i<size();i++)
            if(node[i].accept) end.insert(i);
            else nonend.insert(i);

        auto push=[&](const Subset &s) {
            if(s.empty()) return;
            idx++;
            for(auto u:s) id[u]=idx;
            st.push_back(s);
        };

        push(end),push(nonend);

        for(;;) {
            bool flag=0;
            for(auto &cur:st) {
                Subset ne;
                for(int c=0;c<A;c++) {
                    int aim=id[node[*cur.begin()].ch[c]];
                    for(auto u:cur) if(id[node[u].ch[c]]!=aim) ne.insert(u);
                    if(ne.size()) break;
                }
                if(ne.size()) {
                    for(int u:ne) cur.erase(u);
                    push(ne);
                    flag=1;
                }
            }
            if(!flag) break;
        }

        vector<Node> res(idx+1);
        for(int i=1;i<size();i++) {
            for(int c=0;c<A;c++)
                res[id[i]].ch[c]=id[node[i].ch[c]];
            res[id[i]].accept|=node[i].accept;
        }
        node=res;
        S=id[S];

        debug(S);
        for(int i=1;i<size();i++) debug(i,node[i].ch,node[i].accept);
    }

    bool match(const string &s) {
        int u=S;
        for(auto x:s) {
            int c=x-B;
            if(!node[u][c]) return 0;
            u=node[u][c];
        }
        return node[u].accept;
    }

    int size() { return node.size(); }
    void clear() { node.clear(); }

    DeterministicFiniteAutomaton() {};
    DeterministicFiniteAutomaton(string &s) { build(FA(s)); }
    DeterministicFiniteAutomaton(FA &fa) { build(fa); }
};

void solve() {
    cout<<"[info] please input a regular expression"<<endl<<"> ";
    string regex;
    cin>>regex;
    cout<<"[info] transforming regex..."<<endl;
    regex=shunting_yard(regex);
    cout<<"[info] building NFA..."<<endl;
    FA fa(regex);
    cout<<"[info] transforming NFA to DFA..."<<endl;
    DFA dfa(fa);
    cout<<"[info] minimizing DFA..."<<endl;
    dfa.minimize();
    cout<<"[info] build success"<<endl;
    cout<<"----------------------------------------"<<endl;

    cout<<"[info] please input some strings to match"<<endl;
    for(;;) {
        cout<<"> ";
        string s;
        cin>>s;
        if(dfa.match(s)) cout<<"[ok] Accepted"<<endl;
        else cout<<"[error] Rejected"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}