#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
PII choco[N];
PII box[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>choco[i].first;
    for(int i=1;i<=n;i++) cin>>choco[i].second;
    for(int i=1;i<=m;i++) cin>>box[i].first;
    for(int i=1;i<=m;i++) cin>>box[i].second;
    
    
    multiset<int> st;
    sort(choco+1,choco+1+n);
    sort(box+1,box+1+m);
    for(int i=n,j=m;i>=1;i--){
        while(j&&box[j].first>=choco[i].first) st.insert(box[j--].second);
        auto it=st.lower_bound(choco[i].second);
        if(it==st.end()){
            cout<<"No";
            return 0;
        }
        st.erase(it);
    }
    cout<<"Yes";
    return 0;
}