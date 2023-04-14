#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> idx(n);
    for(int i=0;i<n;i++) idx[i]=i+1;
    
    auto fin=[](int x,int y) {
        cout<<"! "<<x<<' '<<y<<endl;
        int in;
        cin>>in;
    };

    auto ask=[&](int x,int y) {
        cout<<"? "<<x<<' '<<y<<endl;
        int in;
        cin>>in;
        return in;
    };

    auto erase=[&](int x) {
        swap(idx[x],idx.back());
        idx.pop_back();
    };

    while(idx.size()>=3) {
        int x=ask(idx[0],idx[1]);
        int y=ask(idx[1],idx[2]);
        if(x==y) erase(1);
        else if(x<y) erase(0);
        else erase(2);
    }
    fin(idx.front(),idx.back());
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}