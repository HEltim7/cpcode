//参考了nqueen
#include<iostream>
using namespace std;
int ban[100],n,way;
#define nextl (diag_l+pos)>>1 //左对角线，对下次搜索影响的为右移1
#define nextr (diag_r+pos)<<1 //右对角线，对下次搜索影响的为左移1
#define nextc (column+pos) //列，直接加pos
#define full (1<<n)-1 //全可用状态
#define may ~(diag_l|diag_r|column|ban[row])
#define lowbit(x) x&-x //最后可用位 

void dfs(int diag_l,int diag_r,int column,int row){
    int line=full&may;//当前可用位
    if(row==n&&line!=0){//如果row到了最后且这个点没被ban
        way++;
        return;
    }
    while (line){//如果还有可用
        int pos=lowbit(line);//最低位
        line-=pos;//减去最低位的1
        dfs(nextl,nextr,nextc,row+1);
    }
}

int main(){
    cin>>n;
    string in;
    for(int i=1;i<=n;i++){
        cin>>in;
        for(int j=1;j<=n;j++)
            if(in[j-1]=='.')
                ban[i]|=(1<<(n-j)); //ban掉的位置
    }
    dfs(0,0,0,1);//搜索
    cout<<way;
}