#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int N=6e3+10,mod=1e9+7;
bool matrix[N][N];
VII read;
VII tmp;
int n,m,k,maxr,maxc;
bool A,B;
bool isok[N][N];

bool cmp(PII a,PII b){
    return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    m=n;
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        read.emplace_back(a,b);
        if(a==0&&b==0){
            cout<<"No";
            return 0;
        }
        if(a==n) A=1;
        if(b==m) B=1;
    }
    sort(read.begin(),read.end());
    int idx=0;
    //离散行
    for(int i=0;i<read.size();i++){
        //压缩行
        auto [r,c]=read[i];
        if(i&&r-read[i-1].first>=2) idx+=2;
        else if(i&&r-read[i-1].first>=1) idx++;
        else if(i==0&&r!=0) idx=1;
        tmp.emplace_back(read[i].second,idx);
    }
    maxr=idx;
    if(!A) maxr++;
    //离散列
    for(int i=0;i<tmp.size();i++) read[i]=tmp[i];
    idx=0;
    sort(read.begin(),read.end());
    tmp.clear();
    for(int i=0;i<read.size();i++){
        //压缩列
        auto [r,c]=read[i];
        if(i&&r-read[i-1].first>=2) idx+=2;
        else if(i&&r-read[i-1].first>=1) idx++;
        else if(i==0&&r!=0) idx=1;
        tmp.emplace_back(read[i].second,idx);
    }
    maxc=idx;
    if(!B) maxc++;
    for(int i=0;i<tmp.size();i++) read[i]=tmp[i];

    for(auto [r,c]:read) matrix[r][c]=1;
    isok[0][0]=1;
    for(int i=0;i<=maxr;i++)
        for(int j=0;j<=maxc;j++){
            if(i==0&&j==0||matrix[i][j]) continue;
            if(i) isok[i][j]=max(isok[i-1][j],isok[i][j]);
            if(j) isok[i][j]=max(isok[i][j-1],isok[i][j]);
        }
    if(isok[maxr][maxc]) cout<<"Yes";
    else cout<<"No";
    return 0;
}