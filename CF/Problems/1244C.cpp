#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using i128=__int128;

inline ostream &operator<<(ostream &os,unsigned __int128 x) {
    string res;
    while(x) res.push_back(x%10+'0'),x/=10;
    if(res.empty()) res.push_back('0');
    while(res.size()) os<<res.back(),res.pop_back();
    return os;
}

inline ostream &operator<<(ostream &os,__int128 x) {
    if(x<0) return os<<'-'<<-x;
    return os<<(unsigned __int128)x;
}

inline istream &operator>>(istream &is,__int128 &x) {
    string s;
    is>>s;
    x=0;
    for(auto c:s) x=x*10+(c-'0');
    return is;
}

template<typename T> T exgcd(T a,T b,T &x,T &y) {
    if(!b) { x=1,y=0; return a; }
    T res=exgcd(b, a%b, x, y),t=x;
    x=y,y=t-(a/b)*y;
    return res;
}

void solve() {
    i128 a,b,p,n,x,y,z;
    
    cin>>n>>p>>a>>b;
    i128 g=exgcd(a, b, x, y);
    
    if(p%g) {
        cout<<-1<<endl;
        return;
    }
    x*=p/g;
    y*=p/g;
    
    if(x<0) {
        i128 k=((-x)+b/g-1)/(b/g);
        x+=k*b/g;
        y-=k*a/g;
    }
    if(y<0) {
        i128 k=((-y)+a/g-1)/(a/g);
        y+=k*a/g;
        x-=k*b/g;
    }

    z=n-x-y;
    if(x<0||y<0) cout<<-1<<endl;
    else if(z>=0) cout<<x<<' '<<y<<' '<<z<<endl;
    else if(a==b) cout<<-1<<endl;
    else {
        auto _abs=[](i128 x) {
            if(x>=0) return x;
            return -x;
        };

        i128 offset=b/g-a/g;
        i128 k=(-z+_abs(offset)-1)/_abs(offset);
        if(offset<0) k=-k;
        z+=k*offset;
        x-=k*b/g;
        y+=k*a/g;
        if(x>=0&&y>=0&&z>=0) cout<<x<<' '<<y<<' '<<z<<endl;
        else cout<<-1<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}