#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<s;
    return 0;
}