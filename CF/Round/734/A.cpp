#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        int same=0;
        same=n/3;
        if(n%3==0){
            cout<<same<<' '<<same<<endl;
        }
        else if(n%3==1){
            cout<<same+1<<' '<<same<<endl;
        }
        else cout<<same<<' '<<same+1<<endl;
    }
    return 0;
}