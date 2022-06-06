#include<iostream>
#include<stack>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,ans=0,last=1e9+10,in;
    cin>>n;
    stack<int> s;
    for(int i=1;i<=n;i++){
        cin>>in>>in;
        while(s.size()&&in<s.top()) s.pop();
        s.push(in);
    }
    cout<<s.size();
    return 0;
}