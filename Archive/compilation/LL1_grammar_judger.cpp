/*
 * LL(1) grammar judger
 * by HEltim7
 */

#include <set>
#include <map>
#include <array>
#include <queue>
#include <bitset>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
using VI=vector<int>;
using VS=vector<string>;
constexpr char empty_char='%';
const string empty_string="ε";

ostream &operator<<(ostream &os, const string &s) {
    for(auto x:s) 
        if(x==empty_char) os<<empty_string;
        else os<<x;
    return os;
}

ostream &operator<<(ostream &os, const char c) {
    if(c==empty_char) os<<empty_string;
    else os<<string{c};
    return os;
}

struct Grammar {
    constexpr static int A=1<<7;
    bool LL1=1;
    VS gen,select;
    map<string,int> mp;
    string left;
    array<VI, A> right;
    array<bool,A> may_empty;
    array<string,A> first,follow;

    bool ister(char x) { return x>='a'&&x<='z'; }
    bool noter(char x) { return x>='A'&&x<='Z'; }

    // toposort
    void check_empty() {
        VI cnt;
        queue<char> q;
        
        for(int i=0;i<gen.size();i++) {
            cnt.push_back(0);
            if(gen[i]==string{empty_char}) q.push(left[i]);
            else {
                for(char x:gen[i]) {
                    if(ister(x)) {
                        cnt.back()=-1;
                        break;
                    }
                    else if(x!=left[i]) cnt.back()++;
                }
            }
        }

        while(q.size()) {
            char u=q.front();
            q.pop();
            if(may_empty[u]) continue;
            may_empty[u]=1;
            for(int v:right[u]) 
                if(--cnt[v]==0) q.push(left[v]);
        }
    }

    void cal_first_follow() {
        vector<VI> adj(2*A);
        vector<bool> mark(2*A);

        auto new_node=[&]() {
            adj.push_back({});
            mark.push_back({});
            return adj.size()-1;
        };

        for(int i=0;i<gen.size();i++) {
            string &s=gen[i];

            // first
            for(int j=0;j<s.size();j++) {
                adj[s[j]].push_back(left[i]);
                if(ister(s[j])||!may_empty[s[j]]) break;
            }

            // follow
            for(int j=s.size()-1;j>=0;j--) {
                if(noter(s[j])) adj[left[i]+A].push_back(s[j]+A);
                if(!may_empty[s[j]]) break;
            }
            for(int j=1,pre=0;j<s.size();j++) {
                if(may_empty[s[j]]) {
                    int cur=new_node();
                    adj[s[j]].push_back(cur);
                    if(pre) adj[cur].push_back(pre);
                    if(noter(s[j-1])) adj[cur].push_back(s[j-1]+A);
                    pre=cur;
                }
                else {
                    if(noter(s[j-1])) adj[s[j]].push_back(s[j-1]+A);
                    if(pre) adj[s[j]].push_back(pre);
                    pre=0;
                }
            }
        }
        adj['#'].push_back('S'+A);

        auto bfs=[&](char c) {
            queue<int> q;
            mark=vector<bool>(mark.size());
            q.push(c);
            while(q.size()) {
                int u=q.front();
                q.pop();
                for(int v:adj[u]) {
                    if(!mark[v]) {
                        mark[v]=1;
                        if(v<=A) first[v].push_back(c);
                        else if(v<=2*A) follow[v-A].push_back(c);
                        q.push(v);
                    }
                }
            }
        };

        for(int i='a';i<='z';i++) bfs(i);
        bfs('#');
        for(int i='A';i<='Z';i++) if(may_empty[i]) first[i].push_back(empty_char);
    }

    void cal_select() {
        for(int i=0;i<gen.size();i++) {
            string &s=gen[i],ans;
            bool res=1;
            set<char> st;
            for(char c:s) {
                if(c==empty_char) break;
                res&=may_empty[c];
                if(noter(c)) for(char x:first[c]) st.insert(x);
                else st.insert(c);
                if(!res) break;
            }
            if(res) for(char x:follow[left[i]]) st.insert(x);
            st.erase(empty_char);
            for(char x:st) ans.push_back(x);
            select.push_back(ans);
        }
    }

    void check_LL1() {
        bitset<A> a,b;
        for(int i=0;i<gen.size();i++,a.reset()) {
            for(auto x:select[i]) a[x]=1;
            for(int j=i+1;j<gen.size();j++,b.reset()) {
                if(left[i]!=left[j]) continue;
                for(auto x:select[j]) b[x]=1;
                b&=a;
                if(b.any()) {
                    LL1=0;
                    string res;
                    for(int k=0;k<b.size();k++) if(b[k]) res.push_back(k);
                    cout<<"[intersection] select("<<left[i]<<"->"<<gen[i]<<") ∩ "
                    <<"select("<<left[j]<<"->"<<gen[j]<<") = "<<res<<endl;
                }
            }
        }
    }

    void output() {
        for(int i='A';i<='Z';i++) {
            if(first[i].size()) cout<<"[first] first("<<i<<") = "<<first[i]<<endl;
        }
        cout<<endl;
        for(int i='A';i<='Z';i++) {
            if(follow[i].size()) cout<<"[follow] follow("<<i<<") = "<<follow[i]<<endl;
        }
        cout<<endl;
        for(int i=0;i<gen.size();i++) {
            cout<<"[select] select("<<left[i]<<"->"<<gen[i]<<") = "<<select[i]<<endl;
        }
        cout<<endl;
        check_LL1();
    }

    bool match(string s,string cur) {
        if(mp.empty())
            for(int i=0;i<gen.size();i++)
                for(auto x:select[i])
                    mp[string{left[i],x}]=i;
        s.push_back('#');
        int step=0;
        string pre,rule,current;
        reverse(s.begin(),s.end());
        while(s.size()&&cur.size()) {
            if(ister(cur.back())) {
                if(cur.back()!=s.back()) break;
                pre.push_back(cur.back());
                cur.pop_back();
                s.pop_back();
            }
            else {
                auto it=mp.find(string{cur.back(),s.back()});
                if(it==mp.end()) return 0;
                int id=it->second;
                string ne=gen[id];
                reverse(ne.begin(),ne.end());
                cur.pop_back();
                if(ne!=string{empty_char}) cur+=ne;

                current=cur;
                reverse(current.begin(),current.end());
                current=pre+current;
                rule=string{left[id]}+"->"+gen[id];
                cout<<"[match: step "<<++step<<"] rule = "<<rule<<" | "
                    <<"current = "<<current<<endl;
            }
        }
        return (s.empty()||s==string{'#'})&&cur.empty();
    }

    void init(vector<string> &raw) {
        auto transform=[](VS &raw,string aim,char c) {
            VS res;
            for(auto &s:raw) {
                res.push_back("");
                auto &cur=res.back();
                for(int i=0;i<s.size();i++) {
                    if(i+1<s.size()&&string{s[i],s[i+1]}==aim) cur.push_back(c),i++;
                    else cur.push_back(s[i]);
                }
            }
            return res;
        };
        
        auto split=[&](VS &raw) {
            for(auto &s:raw) {
                string res;
                for(int i=3;i<s.size();i++) {
                    if(s[i]!='|') {
                        res.push_back(s[i]);
                        if(s[i]>='A'&&s[i]<='Z') right[s[i]].push_back(left.size());
                    }
                    else {
                        gen.push_back(res);
                        left.push_back(s.front());
                        res.clear();
                    }
                }
                if(res.size()) gen.push_back(res),left.push_back(s.front());
            }
        };

        raw=transform(raw, "ε", empty_char);
        split(raw);
    }

    Grammar() {}
    Grammar(VS &raw) { init(raw); }
} g;

void info(string s) { cout<<"[info] "<<s<<endl; }

void solve(VS &raw) {
    info("initializing...");
    g.init(raw);
    info("step1: Checking for non-terminators that derive the empty string...");
    g.check_empty();
    info("step2: calculating first and follow set...");
    g.cal_first_follow();
    info("step3: calculating select set...");
    g.cal_select();
    info("step4: checking grammar type...");
    cout<<string(74,'-')<<endl;
    g.output();
    cout<<string(74,'-')<<endl;
    info("finished!");
    if(g.LL1) info("this is a LL(1) grammar!");
    else info("this is NOT a LL(1) grammar!");
}

void cli(string file) {
    VS raw;
    string s,ident;
    if(file.empty()) {
        cout<<"====== LL(1) Grammar Judger (interactive mode) ======"<<endl;
        info("please input the grammar (input \"end\" to stop)");
        cout<<"identifier = ",cin>>ident;
        while(cout<<"G["<<ident<<"] = ",cin>>s) {
            if(s=="end") break;
            raw.push_back(s);
        }
    }
    else {
        fstream fin(file,ios::in);
        fin>>ident;
        while(fin>>s) raw.push_back(s);
        fin.close();
    }
    solve(raw);

    if(g.LL1) {
        info("please input some strings to match (input \"end\" to stop)");
        while(cout<<"> ",cin>>s) {
            if(s=="end") break;
            if(g.match(s, ident)) cout<<"[ok] Accepted"<<endl;
            else cout<<"[error] Rejected"<<endl;
        }
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    if(argc<=1) cli("");
    else cli(argv[1]);
    return 0;
}