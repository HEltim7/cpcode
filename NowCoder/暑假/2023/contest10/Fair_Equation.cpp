#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    vector<string> s(3);
    cin>>s[0]>>s[1]>>s[1]>>s[2]>>s[2];
    auto check=[&]() {
        if(stoi(s[0])+stoi(s[1])==stoi(s[2])) {
            cout<<"Yes"<<endl;
            cout<<s[0]<<" + "<<s[1]<<" = "<<s[2]<<endl;
            exit(0);
        }
    };

    check();
    for(int i=0;i<3;i++) {
        for(int j=0;j<s[i].size();j++) {
            for(char k='0';k<='9';k++) {
                auto bak=s[i];
                s[i].insert(s[i].begin()+j,k);
                check();
                s[i]=bak;
            }
        }
        for(char k='0';k<='9';k++) {
            s[i].push_back(k);
            check();
            s[i].pop_back();
        }
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}