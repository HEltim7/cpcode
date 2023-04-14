#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=7;
bool read[N][N];
bool matrix[N][N];
int mvr[N]={0,0,0,0,-1,1};
int mvc[N]={0,0,-1,1,0,0};

inline bool check(int row,int col){
    return row>=1&&row<=5&&col>=1&&col<=5;
}

inline void reverse(int row,int col){
    for(int i=1;i<=5;i++){
        int x=row+mvr[i],y=col+mvc[i];
        if(check(x,y)) matrix[x][y]=!matrix[x][y];
    }
}

int dfs(){
    //枚举第一行
    int ans=7;
    for(int i=0;i<=(1<<5)-1;i++){
        int cnt=0;
        memcpy(matrix,read,sizeof read);
        for(int j=0;j<=4;j++)
            if(i&1<<j)
                cnt++,reverse(1,5-j);
        //递推下层行
        for(int row=2;row<=5;row++){
            if(cnt>6) break;
            for(int col=1;col<=5;col++){
                if(!matrix[row-1][col])
                    cnt++,reverse(row,col);
            }
        }
        //检查最后一行
        bool res=1;
        if(cnt<=6) for(int col=1;col<=5;col++) res&=matrix[5][col];
        else res=0;

        if(res) ans=min(ans,cnt);
    }
    if(ans>6) return -1;
    else return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    while (n--){
        for(int i=1;i<=5;i++){
            string in;
            cin>>in;
            for(int j=1;j<=5;j++) read[i][j]=in[j-1]-'0';
        }
        cout<<dfs()<<endl;
    }
    return 0;
}