#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        set<int> st;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            st.insert(in);
        }
        bool flag=0;
        for(auto x:st){
            if(st.find(x+k)!=st.end()||st.find(x-k)!=st.end()){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}