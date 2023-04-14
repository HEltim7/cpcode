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
    int n;
    cin>>n;
    set<int> arr;
    set<int> st;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(in==0){
            cout<<"NO";
            return 0;
        }
        if(in>0) st.insert(in);
        else arr.insert(in);
    }
    if(arr.empty()||st.empty()||arr.size()>=2||st.size()>=2) cout<<"YES";
    else if(*arr.lower_bound(-2e9)+*st.lower_bound(-1)) cout<<"YES";
    else cout<<"NO";
    return 0;
}