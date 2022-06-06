#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

int x,mod,remian;
string n;

vector<int> operator/(vector<int>a, int b) {
    vector<int>c;
    int temp = 0;
    for (int i = a.size()-1; i >=0; i--)
    {
        temp = temp * 10 + a[i];
        c.push_back(temp / b);
        temp %= b;
    }
    remian=temp;
    reverse(c.begin(), c.end());
    while (c.size() > 1 && *c.rbegin() == 0)c.pop_back();
    return c;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

void fn(){
    vector <int> a;
    vector <int> tmp;
    for(int i=0;i<n.size();i++) a.pub(n[i]-'0');
    tmp.pub(1);
    a=sub(a,tmp);
    int ans=1;

    while(!(a.size()==1&&a[0]==0)){
        a=a/2;
        if(remian==1) ans=ans*x%mod;
        x=x*x%mod;
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>x>>n>>mod;
    fn();
    return 0;
}