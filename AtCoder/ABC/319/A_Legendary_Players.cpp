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

void solve() {
    map<string,int> ans;
    ans["tourist"]=3858;
    ans["ksun48"]=3679;
    ans["Benq"]=3658;
    ans["Um_nik"]=3648;
    ans["apiad"]=3638;
    ans["Stonefeang"]=3630;
    ans["ecnerwala"]=3613;
    ans["mnbvmar"]=3555;
    ans["newbiedmy"]=3516;
    ans["semiexp"]=3481;
    string s;
    cin>>s;
    cout<<ans[s]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}