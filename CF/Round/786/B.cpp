#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    map<string,int> mp;
    int idx=1;
    for(char a='a';a<='z';a++){
        for(char b='a';b<='z';b++){
            if(a==b) continue;
            string s;
            s.push_back(a);
            s.push_back(b);
            mp.emplace(s,idx++);
        }
    }
    while(t--){
        string str;
        cin>>str;
        cout<<mp[str]<<endl;
    }
    return 0;
}