#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10,B=30;
pair<int,int> dif[2][2];

struct Trie {
    struct Node {
        int ch[2];
        int maxx[2][2];
    };
    vector<Node> tr;

    int new_node() {
        tr.push_back({});
        return tr.size()-1;
    }

    vector<int> get(int x) {
        vector<int> res;
        while(x) res.push_back(x&1),x>>=1;
        while(res.size()<B) res.push_back(0);
        reverse(res.begin(),res.end());
        return res;
    }

    void insert(int x,int pos,int val) {
        auto num=get(x),idx=get(pos);
        for(int i=0,u=0;i<B;i++) {
            int j=num[i],k=idx[i];
            tr[u].maxx[j][k]=max(tr[u].maxx[j][k],val);
            if(!tr[u].ch[j^k]) tr[u].ch[j^k]=new_node();
            u=tr[u].ch[j^k];
        }
    }   

    int query(int x,int pos) {
        int res=0;
        auto num=get(x),idx=get(pos);
        for(int i=0,u=0;i<B;i++) {
            int same=num[i]^idx[i];
            auto [j,k]=dif[num[i]][idx[i]];
            res=max(res,tr[u].maxx[j][k]+1);
            u=tr[u].ch[same];
            if(!u) break;
        }
        return res;
    }

    void clear() { tr.clear();new_node(); }
    Trie() { new_node(); }
} trie;

void solve() {
    trie.clear();
    int n,ans=0;
    cin>>n;
    
    for(int i=0;i<n;i++) {
        int in;
        cin>>in;
        int dp=trie.query(in,i);
        trie.insert(in,i,dp);
        ans=max(ans,dp);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    dif[0][1]={1,1};
    dif[1][0]={0,0};
    dif[1][1]={1,0};
    dif[0][0]={0,1};
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}