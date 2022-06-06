//大致思路：位运算+dfs
#include<bits/stdc++.h>
using namespace std;
#define chunk_num(r,c) (r-1)/3*3+(c-1)/3+1 //九宫格序号
#define full (row[1]&row[2]&row[3]&row[4]&row[5]&row[6]&row[7]&row[8]&row[9])//满位
#define trying(i,r,c) (1<<(i-1))&~row[r]&~column[c]&~chunk[chunk_num(r,c)]//尝试判断
int chunk[10],row[10],column[10],data[10][10],isend;

void write(int r,int c){//写入函数
    row[r]|=1<<(data[r][c]-1);
    column[c]|=1<<(data[r][c]-1);
    chunk[chunk_num(r,c)]|=1<<(data[r][c]-1);
}

void dewrite(int r,int c){//擦除函数
    row[r]&=~(1<<(data[r][c]-1));
    column[c]&=~(1<<(data[r][c]-1));
    chunk[chunk_num(r,c)]&=~(1<<(data[r][c]-1));
}

void output(){//输出
    for(int r=1;r<=9;r++){
        for(int c=1;c<=9;c++)
            cout<<data[r][c]<<' ';
    cout<<endl;
    }
    isend=1;//exit(1);不知道为啥exit报错
}

void dfs(int r,int c){
    if(full==511)//填满结束
        output();
    if(isend)return;
    while(data[r][c]){//寻找下一个空位
        if(c!=9)c++;
        else{r++;c=1;}
    }
    for(int i=1;i<=9;i++){//枚举
        if(trying(i,r,c)){
            data[r][c]=i;
            write(r,c);
            dfs(r,c);//下级搜索
            dewrite(r,c);
            data[r][c]=0;//擦除
        }
    }
}

int main(){
    for(int r=1;r<=9;r++){//输入
        for(int c=1;c<=9;c++){
            cin>>data[r][c];
            if(data[r][c]!=0){//过滤0
                write(r,c);
            }
        }
    }
    dfs(1,1);
    return 0;
}