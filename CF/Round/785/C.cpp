#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=4e4,mod=1e9+7,M=510;
vector<int> num,item;
LL dp[N+10];

void init(){
    for(int i=1;i<=N;i++){
        string a=to_string(i);
        string b=a;
        reverse(b.begin(),b.end());
        if(a==b) num.push_back(i);
    }

    dp[0]=1;
    for(auto x:num){
        for(int i=0;(1<<i)*x<=N;i++){
            item.push_back((1<<i)*x);
        }
    }
    for(int i=0;i<item.size();i++){
        for(int j=N;j>=item[i];j--)
            dp[j]=(dp[j]+dp[j-item[i]])%mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}