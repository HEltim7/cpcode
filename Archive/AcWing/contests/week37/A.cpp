#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,a,b,x=-1,y=-1;
    cin>>n>>a>>b;
    bool flag=1;
    for(int i=0;i<=1000&&flag;i++)
        for(int j=0;j<=1000&&flag;j++){
            if(n==a*i+b*j){
                x=i;
                y=j;
                flag=0;
            }
        }
    if(x==-1) cout<<"NO";
    else {
        cout<<"YES"<<endl<<x<<' '<<y;
    }
    return 0;
}