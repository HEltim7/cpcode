#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int n;
int grid[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        if(z!=1) cout<<endl;
        vector<int> path;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>grid[i][j];
        int sum=-1;
        for(int i=1;i<=n;i++){
            if(i&1) 
                for(int j=1;j<=n;j++){
                    if(j==1) sum+=grid[i][j]-grid[i-1][j]>0?1:-1;
                    else sum+=grid[i][j]-grid[i][j-1]>0?1:-1;
                    path.push_back(grid[i][j]);
                }
            else
                for(int j=n;j>=1;j--){
                    if(j==n) sum+=grid[i][j]-grid[i-1][j]>0?1:-1;
                    else sum+=grid[i][j]-grid[i][j+1]>0?1:-1;
                    path.push_back(grid[i][j]);
                }
        }
        if(sum>0) reverse(path.begin(),path.end());
        for(int j=0;j<path.size();j++)
            cout<<path[j]<<(j==path.size()-1?"":" ");
    }
    return 0;
}