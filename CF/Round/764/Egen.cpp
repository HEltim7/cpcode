#include<iostream>
#include<testlib.h>
#include<fstream>
using namespace std;

const int T=10000,N=10,M=10;

int main(int argc, char *argv[])
{
    registerGen(argc,argv,1);
    ofstream coutf("E.in");

    coutf<<T<<endl;
    for(int i=1;i<=T;i++){
        int n=rnd.next(1,N);
        int m=rnd.next(1,M);
        coutf<<n<<' '<<m<<endl;
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=m;j++)
                coutf<<rnd.next(0,9);
            coutf<<endl;
        }
        coutf<<endl;
    }
    return 0;
}
