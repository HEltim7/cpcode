#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef vector<int> VI;
VI ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m,in;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>in,ans.push_back(in);
    for(int i=1;i<=m;i++) cin>>in,ans.push_back(in);
    sort(ans.begin(),ans.end());
    for(auto i:ans) cout<<i<<' ';
    return 0;
}