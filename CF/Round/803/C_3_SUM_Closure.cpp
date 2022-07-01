#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    set<LL> st;
    int cnt=0,zero=0;
    vector<int> arr(1,0);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in) cnt++,arr.push_back(in);
        else zero++;
        st.insert(in);
    }
    debug(arr,st,zero);
    n=arr.size()-1;
    if(cnt==0) cout<<"YES"<<endl;
    else if(cnt>4) cout<<"NO"<<endl;
    else {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++) {
                    LL t=arr[i]+arr[j]+arr[k];
                    if(st.find(t)==st.end()) {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
        if(zero) {
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++) {
                    LL t=arr[i]+arr[j];
                    debug(t);
                    if(st.find(t)==st.end()) {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
        }
        cout<<"YES"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}