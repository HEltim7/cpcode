#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
vector<int> num;

bool ask(int l,int r) {
    cout<<"? "<<r-l<<' ';
    for(int i=l;i<r;i++) cout<<num[i]<<" \n"[i==r-1];
    string s;
    cin>>s;
    return s=="YES";
}

void erase(int l,int r, int &len) {
    int n=num.size();
    vector<int> res(1);
    for(int i=1;i<l;i++) res.push_back(num[i]);
    for(int i=r;i<n;i++) res.push_back(num[i]);
    num=res;
    len-=r-l;
}

bool guess(int x) {
    cout<<"! "<<num[x]<<endl;
    string s;
    cin>>s;
    return s==":)";
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) num.push_back(i);
    int len=n;
    
    while(len>=4) {
        int step=len/4;
        int a=1;
        int b=a+step;
        int c=b+step;
        int d=c+step;
        int e=len+1;
        
        bool A=ask(a, c);
        bool B=ask(b, d);
        if(!A&&B) erase(a, b, len);
        else if(!A&&!B) erase(b, c, len);
        else if(A&&!B) erase(c, d, len);
        else erase(d, e, len);
    }

    int ans=0;
    if(len==3) {
        bool A1=ask(1, 2);
        bool B1=ask(2, 3);
        bool B2=ask(2, 3);
        bool A2=ask(1, 2);
        if(B1==B2) {
            if(B1) ans=2;
            else erase(2, 3, len);
        }
        else {
            auto arr=to_string(A1)+to_string(B1)+to_string(B2)+to_string(A2);
            if(arr=="1101") ans=1; else
            if(arr=="1011") ans=1; else
            if(arr=="0101") ans=3; else
            if(arr=="1010") ans=3; else
            if(arr=="0010") erase(1, 2, len); else
            if(arr=="0100") erase(1, 2, len); else
            if(arr=="1100") erase(3, 4, len); else
            if(arr=="0011") erase(3, 4, len); else;
        }
    }

    if(!ans) {
        if(!guess(1)) ans=2;
        else return;
    }
    guess(ans);
}

int main() {
    solve();
    return 0;
}

/*
_ _ _ _
1 2 3 4

A=1and2
B=2and3

AB:
NY->remove 1
NN->remove 2
YN->remove 3
YY->remove 4

_ _ _
1 2 3

A=1
B=2

ABBA:
ans=1:
TFTF->1100
FTFT->0011
TFTT->1101
TTFT->1011
ans=2:
TFTF->0011
FTFT->1100
TFTT->0010
TTFT->0100
ans=3:
TFTF->0101
FTFT->1010
TFTT->0100
TTFT->0010

*/