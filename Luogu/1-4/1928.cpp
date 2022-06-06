#include<iostream>
using namespace std;

string dfs(string in){
    string ans;
    for(int i=0;i<in.length();i++){
        if(in[i]>='A'&&in[i]<='Z') ans+=in[i];
        else{
            string tmp;
            int head=1,tail=0;
            int cnt=in[i+1]-'0';
            if(in[i+2]>='0'&&in[i+2]<='9'){
                cnt=cnt*10+in[i+2]-'0';
                i++;
            }
            for(int j=i+2;head>tail;j++){
                if(in[j]=='[') head++;
                else if(in[j]==']') tail++;
                if(head>tail) tmp+=in[j];
                i=j;
            }
            tmp=dfs(tmp);
            for(int j=1;j<=cnt;j++){
                ans+=tmp;
            }
        }
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<dfs(str);
    return 0;
}