#include<fstream>
#include<iostream>
using namespace std;

void fileRead(){
    std::fstream ifs;
    
    ifs.open("data.txt");
    std::string str;
    ifs>>str;
    std::cout<<str<<std::endl;
    ifs<<str;
    ifs.close();
}

int main(){
    fileRead();
    return 0;
}