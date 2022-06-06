#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s,res;
    cin>>s;
    for(auto x:s) if(x=='A') res+="BB"; else res+=x;
    string ans;
    for(int i=0;i<res.size();i++){
        if(res[i]=='B'&&res[i+1]=='B') ans.push_back('A'),i++;
        else ans.push_back(res[i]);
    }
    cout<<ans;
    return 0;
}