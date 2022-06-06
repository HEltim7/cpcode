#include<iostream>
#include<fstream>
#include<testlib.h>
using namespace std;

#define endl '\n'
typedef long long LL;

int main(int argc, char *argv[]) {
    freopen64("in.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    int cnt=0;
    vector<pair<int,int>> v;
    for(int i=1111;i<=2000;i++)
        for(int j=7111;j<=8000;j++){
            cnt++;
            v.push_back({i,j});
        }
    cout<<cnt<<endl;
    for(auto [a,b]:v) cout<<a<<' '<<b<<endl;
    return 0;
}