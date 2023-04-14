#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n<=7) cout<<"very easy";
    else if(n<=233) cout<<"easy";
    else if(n<=10032) cout<<"medium";
    else if(n<=114514) cout<<"hard";
    else if(n<=1919810) cout<<"very hard";
    else cout<<"can not imagine";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}