#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=110;
int stack[N];
int idx;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,in,op;
    cin>>n;
    while (n--){
        cin>>op;
        if(op==1) cin>>in,stack[++idx]=in;
        else idx--;
    }
    cout<<stack[idx];
}