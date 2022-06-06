#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<LL> row[N],col[N];
    int matrix[n+1][m+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int in;
            cin>>in;
            row[in].push_back(i);
            col[in].push_back(j);
        }
    LL ans=0;
    for(int i=1;i<N;i++) sort(row[i].begin(),row[i].end());
    for(int i=1;i<N;i++) sort(col[i].begin(),col[i].end());
    for(int i=1;i<N;i++){
        LL pre=0;
        for(int j=0;j<row[i].size();pre+=row[i][j++])
            ans+=row[i][j]*j-pre;
    }
    for(int i=1;i<N;i++){
        LL pre=0;
        for(int j=0;j<col[i].size();pre+=col[i][j++])
            ans+=col[i][j]*j-pre;
    }
    cout<<ans;
    return 0;
}