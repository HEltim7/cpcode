#include<iostream>
#include<stack>
#include<vector>
using namespace std;
string in;

double mul(int idx,vector<char> &op,vector<double> &num){
    double res=num[idx];
    for(int i=idx;i<op.size();i++){
        if(op[i]=='+'||op[i]=='-') break;
        if(op[i]=='*') res*=num[i+1];
        else if(op[i]=='/') res/=num[i+1];
    }
    return res;
}

double dfs(int idx){
    vector<char> op;
    vector<double> num;
    double tmp;
    double ans=0;
    for(int i=idx;i<in.size();i++){
        char x=in[i];
        if(x<='9'&&x>='0') tmp=tmp*10+x-'0';
        else{
            if(tmp) num.emplace_back(tmp);
            tmp=0;
            if(x==')'||x=='#') break;
            else if(x=='('){
                num.emplace_back(dfs(i+1));
                for(;i<in.size();i++) if(x==')') break;
                in[i]='$';
            }
            else op.emplace_back(x);
        }
    }
    for(int i=0;i<op.size();i++){
        char x=op[i];
        if(x=='*'||x=='/'){
            num[i]=mul(i,op,num);
            for(i;i<op.size();i++)
                if(op[i]=='*'||op[i]=='/') continue;
                else break;
        }
    }
    for(int i=0;i<op.size();i++){
        if(i==0) ans=num[i];
        char x=op[i];
        if(x=='+') ans+=num[i+1];
        else if(x=='-') ans-=num[i+1];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    // string in;
    while(getline(cin,in)){
        cout<<dfs(0)<<endl;
    }
    return 0;
}