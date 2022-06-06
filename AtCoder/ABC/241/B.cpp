#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    multiset<int> st;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        st.insert(in);
    }
    while(m--){
        int in;
        cin>>in;
        if(st.find(in)==st.end()){
            cout<<"No";
            return 0;
        }
        st.erase(st.find(in));
    }
    cout<<"Yes";
    return 0;
}