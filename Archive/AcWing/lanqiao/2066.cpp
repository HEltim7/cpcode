#include<iostream>
using namespace std;

int main(){
    string in;
    getline(cin,in);
    for(int i=0;i<in.length();i++){
        if(in[i]<'0'||in[i]>'9')
            cout<<in[i];
        else{
            int repeat=in[i]-'0'-1;
            for(int j=1;j<=repeat;j++) cout<<in[i-1];
        }
    }
    return 0;
}