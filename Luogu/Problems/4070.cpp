#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
LL ans;

struct SAM {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len;
        map<int,int> next;
    };
    vector<Endpos> am;
    int last=0;

    int new_node() {
        am.push_back({});
        return am.size()-1;
    }

    void extend(int c) {
        int p=last;
        int cur=last=new_node();
        am[cur].len=am[p].len+1;
        while(p!=-1) {
            if(!am[p].next.count(c)) am[p].next[c]=cur;
            else {
                int q=am[p].next[c];
                if(am[p].len+1==am[q].len) am[cur].link=q;
                else {
                    int clone=new_node();
                    am[clone]=am[q];
                    am[clone].len=am[p].len+1; 
                    am[cur].link=am[q].link=clone;
                    for(;p!=-1&&am[p].next.count(c)&&am[p].next[c]==q;p=am[p].link)
                        am[p].next[c]=clone;
                }
                break;
            }
            p=am[p].link;
        }
        ans+=am[cur].len-am[am[cur].link].len;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { am.clear(),am.push_back({-1}),last=0; }
    int size() { return am.size(); }
    
    SAM() { am.push_back({-1}); }
    SAM(int sz) { am.reserve(sz),am.push_back({-1}); }
} sam(N*2);

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        sam.extend(in);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}