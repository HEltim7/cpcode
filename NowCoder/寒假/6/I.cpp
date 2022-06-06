#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int k;
    string a,b;
    cin>>k>>a>>b;
    vector<int> A,B;
    for(auto x:a) A.push_back(x-'0');
    for(auto x:b) B.push_back(x-'0');
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    A.push_back(0),B.push_back(0);
    if(A.size()<B.size()) swap(A,B);
    while(A.size()!=B.size()) B.push_back(0);
    for(int i=0,last=0;i<A.size();i++){
        int res=A[i]+B[i]+last;
        last=res/k;
        res=res%k;
        A[i]=res;
    }
    while(A.back()==0&&A.size()>=2) A.pop_back();
    reverse(A.begin(),A.end());
    for(auto x:A) cout<<x;
    return 0;
}