#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;

bool check(int x){
    vector<int> num;
    while(x){
        num.push_back(x%10);
        x/=10;
    }
    reverse(num.begin(),num.end());
    int n=num.front();
    for(auto s:num){
        if(n==s) n++;
        else return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int ans=0;
    for(int i=1;i<=2022;i++){
        if(check(i)) ans++;
    }
    cout<<ans;
    return 0;
}