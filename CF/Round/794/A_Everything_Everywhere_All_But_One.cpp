#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'

void solve() {
    int n;
    cin>>n;
    int sum=0;
    set<int> st;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        sum+=in;
        st.insert(in);
    }
    int avg=sum/n;
    if(st.count(avg)&&avg*n==sum) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}