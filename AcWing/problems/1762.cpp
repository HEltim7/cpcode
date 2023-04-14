#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=110;
string cow[N];
string bak[N];
int mv[N];

void move(int n){
    for(int i=1;i<=n;i++) cow[i]=bak[mv[i]];
    for(int i=1;i<=n;i++) bak[i]=cow[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>mv[i];
    for(int i=1;i<=n;i++) cin>>bak[i];
    for(int i=1;i<=3;i++) move(n);
    for(int i=1;i<=n;i++) cout<<cow[i]<<endl;
    return 0;
}