#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==3){
            cout<<"3 2 1"<<endl
                <<"1 3 2"<<endl
                <<"3 1 2"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++) num[i]=num[i+n]=n-i+1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=i+n-1;j++)
                cout<<num[j]<<' ';
            cout<<endl;
        }
    }
    return 0;
}