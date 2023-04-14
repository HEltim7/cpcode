#include<iostream>
using namespace std;

#define endl '\n'

int ans[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    for(auto x:s){
        if(x!='5') ans[x-'0']++,ans[5]++;
    }
    for(int i=1;i<=9;i++) cout<<ans[i]<<' ';
    return 0;
}