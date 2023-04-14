#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
int idxs[10],slen;

string add(string &a,string &b)
{
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

    vector<int> C;
    A.resize(max(A.size(),B.size()));
    B.resize(max(A.size(),B.size()));

    int temp=0;
    for(int i=0;i<A.size();i++)
    {
        temp+=A[i]+B[i];
        C.push_back(temp%10);
        temp/=10;
    }
    if(temp!=0) C.push_back(temp);
    
    string c="";
    for(int i=C.size()-1;i>=0;i--) c.push_back(C[i]+'0');
    return c;
}
int cmp(string &a,string &b)
{
    if(a.size()>b.size()) return 1;
    else if(a.size()<b.size()) return -1;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    }
    return 0;
}

int k;
string s,ans;
void dfs(int cur,int deep) {
    if(deep>k) {
        string res;
        for(int i=0;i<=idxs[1];i++) res.push_back(s[i]);
        // vector<string> v;
        // v.push_back(res);
        for(int i=1;i<=k;i++) {
            string t;
            for(int j=idxs[i]+1;j<=idxs[i+1];j++) t.push_back(s[j]);
            // v.push_back(t);
            res=add(res,t);
        }
        if(cmp(res,ans)==-1) ans=res,debug(v);
        return;
    }
    for(int i=cur;i+1<s.size();i++) {
        idxs[deep]=i;
        dfs(i+1,deep+1);
    }
}

void solve() {
    int len;
    cin>>len>>k>>s;
    ans=s;
    idxs[k+1]=s.size()-1;
    dfs(0,1);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}