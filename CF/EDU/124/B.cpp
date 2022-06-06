#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        LL a=1,b;
        vector<int> res;
        res.push_back(a);
        bool ans=1;
        for(int i=2;i<=n&&ans;i++){
            b=a*3;
            if(b>1e9) ans=0;
            res.push_back(b);
            a=b;
        }
        if(ans){
            cout<<"YES"<<endl;
            for(auto x:res) cout<<x<<' ';
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}