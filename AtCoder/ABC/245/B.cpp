#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2000+10;
bool arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(in>=0) arr[in]=1;
    }
    for(int i=0;i<=2000;i++)
        if(arr[i]==0){
            cout<<i;
            break;
        }
    return 0;
}