//错误做法，正解见alt
#include<iostream>
#include<string>
using namespace std;

int main(){
    string in;
    long ans=0,tmpans=0,head,A2B,B2A,A2B2,B2A2;
    bool isB=0;
    getline(cin,in);
    for(int i=0;i<in.length();i++){
        if(in[i]=='A'&&in[i+1]=='B'){
            A2B=i;
        }
        else if(in[i]=='B'&&in[i+1]=='A'){
            B2A=i;
            int j=0;
            for(;j<in.length();j++){
                if(in[i+j+1]=='B'){
                    A2B2=i+j;
                    break;
                }
            }
            for(;j<in.length();j++){
                if(in[i+j+1]=='A'){
                    B2A2=i+j;
                    break;
                }
            }
            
        }
        tmpans++;
    }
}