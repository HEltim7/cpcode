#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<LL> a,b;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            a.push_back(in);
        }
        for(int i=1;i<=n;i++) {
            int in;
            cin>>in;
            b.push_back(in);
        }

        LL ans=0;
        for(int i=1;i<n;i++){
            ans+=min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1])
                    ,abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}