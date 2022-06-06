#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef vector<int> VI;
const int N=150000+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,in;
    cin>>t;
    while(t--){
        VI loc[N];
        cin>>n;
        for(int i=1;i<=n;i++) cin>>in,loc[in].push_back(i);
        int ans=N;
        for(int i=1;i<N;i++)
            for(int j=1;j<loc[i].size();j++)
                ans=min(ans,loc[i][j]-loc[i][j-1]);
        if(ans==N) cout<<"-1"<<endl;
        else cout<<n-ans<<endl;
    }
    return 0;
}