#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

int duval(const string &s) {
    int res=0;
    for(int i=0;i<s.size();) {
        int j=i,k=i+1;
        while(k<s.size()&&s[j]<=s[k]) {
            if(s[j]<s[k]) j=i;
            else j++;
            k++;
        }
        while(i<=j) {
            i+=k-j;
            res^=i;
        }
    }
    return res;
}

void solve() {
    string s;
    cin>>s;
    cout<<duval(s)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}