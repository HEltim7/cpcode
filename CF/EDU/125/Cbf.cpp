#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
//1 left 0 right

vector<int> get(int x){
    vector<int> num;
    while(x){
        num.push_back(x&1);
        x/=2;
    }
    return num;
}

bool check_1(int x){
    auto num=get(x);
    reverse(num.begin(),num.end());
    int cnt=0;
    for(auto s:num){
        if(s==1) cnt++;
        else cnt--;
        if(cnt<0) return 0;
    }
    return cnt==0;
}

bool check_2(int x){
    auto num=get(x);
    vector<int> tmp=num;
    reverse(num.begin(),num.end());
    return num==tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    for(int i=1;i<=100;i++){
        auto v=get(i);
        reverse(v.begin(),v.end());
        for(auto x:v) cout<<x;
        cout<<endl;
        cout<<check_1(i)<<' '<<check_2(i)<<endl;
    }
    return 0;
}