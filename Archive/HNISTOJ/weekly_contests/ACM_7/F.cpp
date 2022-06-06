#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int matrix[110][110]={0},step,r,c;
char dir;

void out(int len){
    int i;
    if(dir=='e'){
        while(len-->0){
            matrix[r][c++]=++step;
            
        }
    }
    else if (dir=='w')
    {
        while(len-->0){
            matrix[r][c--]=++step;
        }
    }
    else if (dir=='s')
    {
        while (len-->0)
        {
            matrix[r++][c]=++step;
        }
    }
    else
    {
        while(len-->0){
            matrix[r--][c]=++step;
        }
    }
    return;
}

int main(){
    int in;
    bool isnotfirst=0;
    while(cin>>in&&in!=EOF){
        step=0;
        if(in==1&&isnotfirst){
            cout<<endl<<endl;
            cout<<'1';
            continue;
        }
        else if(in==1&&!isnotfirst){
            cout<<'1';
            isnotfirst=1;
            continue;
        }
        else if(in==2&&isnotfirst){
            cout<<endl<<endl<<"1 2";
            cout<<endl<<endl<<"4 3";
            continue;
        }
        else if(in==2&&!isnotfirst){
            cout<<"1 2"<<endl<<endl<<"4 3";
            isnotfirst=1;
            continue;
        }
        int len=in-1;
        r=1,c=1;
        dir='e';
        for(;;){
            out(len);
            dir='s';
            out(len);
            dir='w';
            out(len);
            dir='n';
            out(len);

            dir='e';
            len=len-2;
            r++;
            c++;
            if(in%2==1){
                if(len==0){
                    matrix[r][c]=++step;
                    break;
                }
            }
            else
            {
                if(len==-1){
                    break;
                }
            }
            
        }
        if(!isnotfirst){
            for(int con=1;con<=in;con++){
                cout<<matrix[1][con]<<' ';
            }
            for(int row=2;row<=in;row++){
                cout<<endl;
                cout<<endl;
                for(int con=1;con<=in;con++){
                    cout<<matrix[row][con]<<' ';
                }
            }
        }
        else
        {
            for(int row=1;row<=in;row++){
                cout<<endl;
                cout<<endl;
                for(int con=1;con<=in;con++){
                    cout<<matrix[row][con]<<' ';
                }
            }
        }
        
        isnotfirst=1;
    }
    return 0;
}