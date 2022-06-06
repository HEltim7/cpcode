#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int a,b,c;
    a=b=c=0;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a+=x,b+=y,c+=z;
    }
    if(a==0&&b==0&&c==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}