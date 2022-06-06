#include<iostream>
#include<cassert>
using namespace std;

// #define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
LL ans;

inline LL f(LL num){
    LL res=-num;
    for(LL i=1;i<=num/i;i++){
        if(num%i==0) {
            if(i!=num/i) res+=i+num/i;
            else res+=i;
        }
    }
    debug(res);
    ans++;
    assert(res);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL x=720;
    while((x=f(x))!=1) ;
    cout<<ans;
    return 0;
}