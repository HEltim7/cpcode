#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string a="edgnb";
    string str;
    cin>>str;
    int ans=0;
    for(int i=0;i<str.size();i++)
        for(int j=0;j<a.size();j++){
            if(a[j]!=str[i+j]) break;
            if(j==a.size()-1) ans++;
        }
    cout<<ans;
    return 0;
}