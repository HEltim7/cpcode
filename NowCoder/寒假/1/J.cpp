#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<int> a;
        vector<int> b;
        int A,B,n,in;
        cin>>A>>B>>n;
        for(int i=1;i<=A;i++) cin>>in,a.push_back(in);
        for(int i=1;i<=B;i++) cin>>in,b.push_back(in);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=0;
        if(n==1){
            if(a.size()) ans=max(ans,a.back());
            if(b.size()) ans=max(ans,b.back());
            cout<<ans<<endl;
            continue;
        }
        int aq=(n+1)/2;
        int bq=n-aq;
        if(aq>a.size()){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=aq;i++) ans+=a.back(),a.pop_back();
        for(int i=1;i<=bq;i++){
            if(a.empty()) ans+=b.back(),b.pop_back();
            else if(b.empty()) ans+=a.back(),a.pop_back();
            else if(a.back()>b.back()) ans+=a.back(),a.pop_back();
            else ans+=b.back(),b.pop_back();
        }
        cout<<ans<<endl;
    }
    return 0;
}