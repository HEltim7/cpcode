#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string in;
    getline(cin,in);
    for(int i=0;i<in.size();i++) {
        if(in[i]>='a'&&in[i]<='z'&&(i==0||in[i-1]<'a'||in[i-1]>'z'))
            cout<<(char)(in[i]+'A'-'a');
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    string in;
    getline(cin,in);
    while(t--) solve();
    return 0;
}