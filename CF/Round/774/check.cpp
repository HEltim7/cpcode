#include<iostream>
#include<fstream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    fstream std("std.txt"),out("out.txt");
    int a,b;
    int cnt=0;
    while(std>>a&&out>>b){
        cnt++;
        if(a!=b) cout<<cnt<<endl;
    }
    return 0;
}