#include<iostream>
#include<vector>
using namespace std;

// return value
struct REVAL{
    double res;
    int idx;
};
string in;

class fn{
    public:
        REVAL readnum(int idx);
        REVAL mul(int idx);
        REVAL getsum(int idx);
} F;

//读入一个数
REVAL fn::readnum(int idx){
    if(in[idx]=='(') return F.getsum(idx+1);
    double res=0;
    while(idx<in.size()-1){
        char x=in[idx];
        if(x<='9'&&x>='0') res=res*10+x-'0';
        else break;
        idx++;
    }
    return {res,idx};
}

//计算一个乘除段
REVAL fn::mul(int idx){
    if(in[idx]=='(') return getsum(idx+1);
    double ans=F.readnum(idx).res;
    idx=F.readnum(idx).idx;
    while(idx<in.size()-1){
        char x=in[idx];
        if(x=='+'||x=='-') break;
        REVAL val;
        if(x=='(') val=F.getsum(idx+1);
        else val=F.readnum(idx+1);

        if(x=='*') ans*=val.res;
        else if(x=='/') ans/=val.res;
        idx=val.idx;
    }
    return {ans,idx};
}

//求一个子串的值
REVAL fn::getsum(int idx){
    double ans=1e9;
    while (idx<in.size()-1){
        char x=in[idx];
        REVAL val;
        if(x<='9'&&x>='0'||x=='(') val=F.readnum(idx);//数或式子
        else if(x==')') return {ans,idx+1};
        else val=F.readnum(++idx);//运算符
        if(ans==1e9) ans=val.res,idx=val.idx;
        else{
            char ne=in[val.idx];
            if(ne=='*'||ne=='/') val=F.mul(idx);

            if(x=='+') ans+=val.res;
            else if(x=='-') ans-=val.res;
            else if(x=='*') ans*=val.res;
            else if(x=='/') ans/=val.res;
            idx=val.idx;
        }
    }
    return {ans,idx};
}

int main(){
    while (cin>>in){
        cout<<F.getsum(0).res<<endl;
    }
    return 0;
}

/*
2*(2+3*2) =16
(2*300+2)*(2+2*4*2+1)*(2*3+2)*(2+2*4*2+1) =8*19
*/