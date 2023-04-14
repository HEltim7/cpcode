#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    vector<LL> num;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        num.push_back(in);
    }
    LL ans=1;
    for(auto x:num) ans=lcm(ans,x);
    cout<<ans%N;
}

/*
4
25000
25001
25002
25003
195359378437575000
*/