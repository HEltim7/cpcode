#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    cin>>n>>m;

    set<int> st;
    for(int i=1,j=1;i<=m;i++) {
        int op;
        cin>>op;
        if(op==1) {
            st.insert(j);
            j++;
        }
        else if(op==2) {
            int x;
            cin>>x;
            st.erase(x);
        }
        else {
            cout<<*st.begin()<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}