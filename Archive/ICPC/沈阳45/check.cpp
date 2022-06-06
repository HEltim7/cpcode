#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream fin,out,std;
    ofstream res;
    fin.open("in.txt",ios::in);
    out.open("out.txt",ios::in);
    std.open("std.txt",ios::in);
    res.open("res.txt",ios::out);
    int t;
    fin>>t;
    for(int i=1;i<=t;i++){
        int a,b,x,y;
        fin>>a>>b;
        out>>x;
        std>>y;
        if(x!=y) res<<a<<' '<<b<<endl<<x<<' '<<y<<endl<<"----"<<endl;
    }
    return 0;
}