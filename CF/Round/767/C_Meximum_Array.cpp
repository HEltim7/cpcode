#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N],suf[N];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<int> ans;
        multimap<int,int> mp;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i],mp.emplace(arr[i],i);
        for(int i=1;i<=n;i++) {
            int idx=i;
            int cur=-1;
            for(;;){
                auto it=mp.find(cur+1);
                if(it!=mp.end()) cur++,idx=max(idx,it->second);
                else break;
            }
            for(int j=i;j<=idx;j++)
                mp.erase(mp.find(arr[j]));
            ans.push_back(cur+1);
            i=idx;
        }
        cout<<ans.size()<<endl;
        for(auto x:ans) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}