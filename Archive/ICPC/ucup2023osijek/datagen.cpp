#include <iostream>
#include <fstream>
#include <testlib.h>
using namespace std;

#define endl '\n'
typedef long long LL;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    
    for(int i=1;i<=100;i++) {
        fstream fout(to_string(i)+".in",ios::out);
        int n=1e6;
        for(int i=1;i<=n;i++) fout<<char(rnd.next(33,126));
        fout<<endl;
        fout<<rnd.next(2,int(1e9))<<endl;
    }
}