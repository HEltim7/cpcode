#include <iostream>
#include <fstream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("in.txt","w",stdout);
    int n=500,idx=0;
    cout<<1<<endl;
    cout<<2+n+n*n<<endl;
    cout<<++idx<<' '<<++idx<<endl;
    for(int i=1;i<=n;i++) {
        int t=++idx;
        cout<<2<<' '<<t<<endl;
        for(int i=1;i<=n;i++) cout<<t<<' '<<++idx<<endl;
    }

}