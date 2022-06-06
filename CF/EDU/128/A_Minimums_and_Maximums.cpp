#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b<d){
            swap(a,c);
            swap(b,d);
        }
        if(a<=d){
            cout<<max(a,c)<<endl;
        }
        else{
            cout<<a+c<<endl;
        }
    }
    return 0;
}