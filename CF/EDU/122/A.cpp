#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0){
            cout<<n<<endl;
            continue;
        }
        n/=10;
        for(int i=0;i<=9;i++){
            int res=n*10+i;
            if(res%7==0){
                cout<<res<<endl;
                break;
            }
        }
    }
    return 0;   
}