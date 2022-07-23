#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        // bool flag=0;
        // if(n%4==0||(n%400==0)){
        //     for(int i=2;i*i<=n;i++){
        //         if(n%i==0){
        //             cout<<"no"<<endl;
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(!flag) cout<<"yes"<<endl;
        // }
        // else cout<<"no"<<endl;
        cout<<"no"<<endl;
    }
    return 0;
}