#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int in;
    cin>>in;
    if(in>=60) cout<<"22:"<<((in-60)<10?"0":"")<<in-60;
    else cout<<"21:"<<(in<10?"0":"")<<in;
    return 0;
}