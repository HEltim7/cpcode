#include<iostream>
#include<fstream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ifstream out("out.txt"),std("std.txt");
    ofstream res("res.txt");
    int a,b,cnt=1;
    while(out>>a&&std>>b){
        if(a!=b) res<<cnt<<endl;
        cnt++;
    }
    return 0;
}