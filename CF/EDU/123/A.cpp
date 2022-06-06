#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int r,g,b,R,G,B;
        for(int i=0;i<s.size();i++)
            if(s[i]=='r') r=i;
            else if(s[i]=='R') R=i;
            else if(s[i]=='b') b=i;
            else if(s[i]=='B') B=i;
            else if(s[i]=='g') g=i;
            else if(s[i]=='G') G=i;
        if(r<R&&g<G&&b<B) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}