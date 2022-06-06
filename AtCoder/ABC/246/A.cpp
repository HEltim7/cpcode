#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> x,y;
    int in;
    for(int i=1;i<=3;i++){
        int a,b;
        cin>>a>>b;
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(x[0]==x[1]) cout<<x.back()<<' ';
    else cout<<x.front()<<' ';
    if(y[0]==y[1]) cout<<y.back();
    else cout<<y.front();
    return 0;
}