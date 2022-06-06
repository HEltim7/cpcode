#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=200000+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,x=0;
    cin>>n;
    bool flag=1,tmp=1;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(i>=2&&num[i]!=num[i-1]) flag=0;
        if(tmp&&x<num[i]) x=num[i];
        else if(tmp&&x>num[i]) tmp=0;
    }
    if(flag){
        cout<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(num[i]!=x) cout<<num[i]<<' ';
    }
    return 0;
}