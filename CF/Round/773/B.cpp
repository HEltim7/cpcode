#include<iostream>
#include<set>
#include<map>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> st;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            auto it=st.find(a);
            if(it!=st.end()) it->second++;
            else st.insert({a,1});
        }
        int cnt=st.size();
        for(int i=1;i<=n;i++){
            if(i<=cnt) cout<<cnt<<' ';
            else cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}