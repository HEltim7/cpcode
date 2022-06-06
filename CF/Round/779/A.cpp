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
        int n,ans=0;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(i+1<s.size()&&s[i+1]=='0') ans+=2;
                else if(i+2<s.size()&&s[i+2]=='0') ans+=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}