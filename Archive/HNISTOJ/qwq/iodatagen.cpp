#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream io;
    io.open("io1e8.txt", ios::out);
    for(int i=1;i<=1e8;i++){
        io<<i<<' ';
    }
    cout<<"finished";
    void close();
    return 0;
}