#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    set<int> st;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        st.insert(in);
    }
    cout<<st.size();
    return 0;
}