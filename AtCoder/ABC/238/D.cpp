#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        LL a,s;
        cin>>a>>s;
        if(a>s){
            cout<<"No"<<endl;
            continue;
        }
        s-=a;
        if((a&s)==a) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}