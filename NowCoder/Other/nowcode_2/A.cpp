#include<bits/stdc++.h>
using namespace std;
bool board[10][10];
int rr[4],cc[4],sum,may;

bool isok(){
    if(rr[1]==rr[2]&&rr[2]==rr[3]){return 1;}
    if(cc[1]==cc[2]&&cc[2]==cc[3]){return 1;}
    if(rr[1]==cc[1]&&rr[2]==cc[2]&&rr[3]==cc[3]){return 1;}
    if(((rr[1]+cc[1])==4)&&((rr[2]+cc[2])==4)&&((rr[3]+cc[3])==4)){return 1;}
    return 0;
}

void dfs(int r,int c,int deep){
    if(deep<=3){
        for(;r<=3;r++){
            for(;c<=3;c++){
                if(!board[r][c]){//空
                    board[r][c]=1;
                    rr[deep]=r;
                    cc[deep]=c;
                    dfs(r,c,deep+1);
                    board[r][c]=0;
                }
            }
            c=1;
        }
    }
    else {
        may++;
        if(isok()){
            sum++;
            // for(int i=1;i<=3;i++){
            //     cout<<rr[i]<<' '<<cc[i]<<endl;
            // }
            // cout<<"----------"<<endl;
        }
    }
}

int main(){
    char in;
    int r=1,c=1;
    memset(board,0,sizeof(board));

    for(int i=1;i<=9;i++){
        if(cin>>in&&in=='X')
            board[r][c]=1;
        if(c++>=3){
            r++;
            c=1;
        }
    }

    dfs(1,1,1);
    if(sum==0){cout<<'0';return 0;}
    int tmp=__gcd(sum,may);
    cout<<sum/tmp<<' '<<may/tmp;
    return 0;
}