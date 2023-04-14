#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <array>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using MST=multiset<int>;
constexpr int n=13,m=4;

array<MST,4> hand,desk;
array<PII,4> state;

void solve() {
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            int in;
            cin>>in;
            hand[i].insert(in);
        }
    }

    int q,x,y,cur=0;
    cin>>q;
    while(q--) {
        char op;
        cin>>op;
        if(op=='S') {
            cin>>x>>y;
            for(int i=1;i<=y;i++) {
                int in;
                cin>>in;
                desk[cur].insert(in);
                hand[cur].erase(hand[cur].find(in));
            }
            state[cur]={y,x};
        }
        else if(op=='!') {
            cin>>y;
            for(int i=1;i<=y;i++) {
                int in;
                cin>>in;
                desk[cur].insert(in);
                hand[cur].erase(hand[cur].find(in));
            }
            state[cur]={y,x};
        }
        else {
            int last=(cur-1+m)%m;
            int cnt=desk[last].count(state[last].second);

            int loser=cnt==state[last].first?cur:last;
            for(int i=0;i<m;i++) {
                for(auto x:desk[i]) hand[loser].insert(x);
                desk[i].clear();
            }
        }

        cur=(cur+1)%m;
    }

    for(int i=0;i<m;i++) {
        for(auto x:hand[i]) cout<<x<<' ';
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}