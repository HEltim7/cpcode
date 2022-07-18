#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[1<<7];

void solve() {
    string in;
    cin>>in;
    for(auto x:in) cnt[x]++;
    for(int i=0;i<(1<<7);i++) {
        if(cnt[i]==1) {
            cout<<(char)i;
            return;
        }
    }
    cout<<-1;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}