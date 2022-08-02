#include <iostream>
#include <fstream>
#include <testlib.h>
#include <vector>
using namespace std;

#define endl '\n'
typedef long long LL;

const int N=1e5+10;
int n=20,m=20;
int arr[N];
tuple<int,int,int> q[N];
fstream fin,fout;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

void solve() {
    fout.open("F.out",ios::out);
    for(int i=1;i<=n;i++) {
        auto [op,l,r]=q[i];
        if(op==1) sort(arr+l,arr+r+1),debug(arr,1,n);
        else if(op==2) sort(arr+l,arr+r+1,greater<int>()),debug(arr,1,n);
        else {
            int res[2]={};
            for(int i=l;i<=r;i++) {
                if(arr[i]&1) res[1]=max({res[1],res[0]+1,1});
                else res[0]=max({res[0],res[1]+1,1});
            }
            fout<<max(res[0],res[1])<<endl;
        }
    }
}

void output() {
    fin<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++) fin<<arr[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) {
        auto [op,l,r]=q[i];
        fin<<op<<' '<<l<<' '<<r<<endl;
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    fin.open("F.in",ios::out);

    vector<int>tmp=rnd.distinct(n,1,n);
    for(int i=0;i<n;i++) arr[i+1]=tmp[i];
    for(int i=1;i<=m;i++) {
        int op=rnd.next(1,3);
        // int l=rnd.wnext(1,n,-1);
        int l=rnd.next(1,n);
        int r=rnd.next(l,n);
        q[i]={op,l,r};
    }
    output();
    solve();
}