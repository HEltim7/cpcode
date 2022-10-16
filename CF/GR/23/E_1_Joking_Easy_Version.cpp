#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;

bool ask(int l,int r) {
    cout<<"? "<<r-l+1<<' ';
    for(int i=l;i<=r;i++) cout<<i<<' ';
    cout<<endl;
    string s;
    cin>>s;
    return s=="YES";
}

bool check() {
    bool res=ask(1,1);
    return res;
}

bool guess(int x) {
    cout<<"! "<<x<<endl;
    string s;
    cin>>s;
    return s==":)";
}

void solve() {
    int n;
    cin>>n;
    bool A=guess(1);
    if(A) return;

    int l=1,r=n;
    while(l<r) {
        bool pre=A==check();
        int mid=l+r>>1;
        bool L=ask(l, mid);
        bool R=ask(mid+1, r);
        if(L==R) {
            bool suf=A==check();
            if(!suf) {
                
            }
            if(A==check()) {
                R^=1;
            }
            if(R) l=mid+1;
            else r=mid;
        }
        else {
            if(L) r=mid;
            else l=mid+1;
        }
    }
    guess(l);
}

int main() {
    solve();
    return 0;
}