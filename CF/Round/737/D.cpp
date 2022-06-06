#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=3e5+10;
typedef pair<int,int> PII;
vector<PII> seg[N];
PII dp[N][2];

bool check(int a,int b){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int line,l,r;
        cin>>line>>l>>r;
        seg[line].push_back({l,r});
    }
    for(int i=1;i<=n;i++){
        
    }
}