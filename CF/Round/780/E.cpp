#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=4e3+10;
int matrix[N][N];
int pre[N][N],cnt[N][N];
int n;

// #define __LOCAL
#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

inline int get_all(int r,int c){
    return pre[r][c]-pre[r-n][c]-pre[r][c-n]+pre[r-n][c-n];
}

inline int get(int r,int c){
    return cnt[r][c]-cnt[r-n][c-n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            string in;
            cin>>in;
            for(int j=0;j<in.size();j++)
                matrix[i][j+1]=matrix[i][j+1+n]=in[j]-'0';
        }
        
        for(int j=1;j<=2*n;j++)
            for(int i=1;i<=n;i++)
                matrix[i+n][j]=matrix[i][j];
        for(int i=1;i<2*n;i++)
            for(int j=1;j<2*n;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+matrix[i][j];
                cnt[i][j]=cnt[i-1][j-1]+matrix[i][j];
            }

        // for(int i=1;i<2*n;i++) cat_arr(matrix[i],1,2*n);

        int ans=n*n;
        for(int i=n;i<2*n;i++)
            for(int j=n;j<2*n;j++){
                ans=min(ans,get_all(i,j)-get(i,j)+n-get(i,j));
                debug(i,j,get_all(i,j),get(i,j),ans);
            }
        cout<<ans<<endl;
    }
    return 0;
}