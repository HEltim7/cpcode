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
    while(t--){
        string in;
        cin>>in;
        int sum=0;
        for(auto x:in)
            sum+=x-'a'+1;
        int bob=0;
        if(in.size()%2!=0){
            bob=min(in.front()-'a'+1,in.back()-'a'+1);
            sum-=bob;
        }
        if(sum>bob){
            cout<<"Alice "<<sum-bob<<endl;
        }
        else cout<<"Bob "<<bob-sum<<endl;
    }
    return 0;
}