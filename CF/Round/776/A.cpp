#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        char c;
        cin>>s>>c;
        bool flag=0;
        if(s.size()==1&&s.front()==c) flag=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==c&&i%2==0&&(s.size()-1-i)%2==0) flag=1;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}