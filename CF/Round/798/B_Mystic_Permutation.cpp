#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    set<int> st;
    for(int i=1;i<=n;i++) cin>>arr[i],st.insert(arr[i]);
    if(n==1) {
        cout<<"-1\n";
        return;
    }
    for(int i=1;i<=n;i++) {
        auto it=st.begin();
        if(*it==arr[i]||st.size()==2&&*st.rbegin()==arr[i+1]) {
            it=next(it);
            cout<<*it<<' ';
        }
        else {
            cout<<*it<<' ';
        }
        st.erase(it);
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}