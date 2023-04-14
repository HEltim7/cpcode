#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const double eps=1e-8;
const int INF=0x3f3f3f3f,mod=998244353;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(...)
#include<debug>
#else
#define debug(...)
#endif

int ex1;
int ex2;
int len1,len2;
int n;
string s;
string res;
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
void dfs(vector<int> &ver,int id,int num1,int num2)
{
    if(id==n)
    {
        string now="";
        int g=0;
        for(auto len:ver)
        {
            string str=s.substr(g,len);
            now=add(now,str);
            g+=len;
        }
        if(cmp(now,res)==-1)
        {
            res.swap(now);
        }
        return ;
    }
    if(num1<ex1)
    {
        ver.push_back(len1);
        dfs(ver,id+len1,num1+1,num2);
        ver.pop_back();
    }
    if(num2<ex2)
    {
        ver.push_back(len2);
        dfs(ver,id+len2,num1,num2+1);
        ver.pop_back();
    }
}
void solve()
{
    res.clear();
    int k;
    scanf("%d%d",&n,&k);
    cin>>s;
    res=s;
    k++;
    ex2=n%k;//len2的数量
    ex1=k-ex2;
    len1=n/k;
    len2=(n+k-1)/k;
    vector<int> ver;
    dfs(ver,0,0,0);
    cout<<res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
}