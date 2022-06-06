#include<iostream>
#include<fstream>
using namespace std;

int main() {

    //要转化的代码放在同目录下的in.cpp里,结果会放在out.json里面

    ifstream fcin("in.txt");
    ofstream fcout("out.json");
    cout<<"snippet 名称"<<endl<<">";
    string in;
    char _='"';
    string tab="    ";
    getline(cin,in);
    fcout<<_<<in<<_<<": {"<<endl;

    cout<<"触发词"<<endl<<">";
    getline(cin,in);
    fcout<<tab<<_<<"prefix"<<_<<": "<<_<<in<<_<<","<<endl;

    fcout<<tab<<_<<"body"<<_<<": ["<<endl;
    while(getline(fcin,in)){
        fcout<<tab<<tab<<_;
        for(auto x:in){
            if(x=='\\'||x==_) fcout<<'\\';
            fcout<<x;
        }
        fcout<<_<<","<<endl;
    }
    fcout<<tab<<"],"<<endl;

    cout<<"描述"<<endl<<">";
    getline(cin,in);
    fcout<<tab<<_<<"description"<<_<<": "<<_<<in<<_<<","<<endl;
    fcout<<"},"<<endl;
    return 0;
}