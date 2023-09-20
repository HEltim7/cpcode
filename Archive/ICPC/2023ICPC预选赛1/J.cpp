#include <iomanip>
#include <iostream>
#include <cstring>
#include <ostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

#define double long double

struct Point {
    double x,y;
    Point operator-(const Point& o)const {
        return {x-o.x,y-o.y};
    }
};
ostream& operator<<(ostream& os, const Point& o) {
    return os<< "(" <<o.x<<","<<o.y<<")";
}

const double sq2=sqrt(2);

void solve() {
    vector<pair<int,int>> a(4);
    for(auto& [x,y]:a) cin>>x>>y;
    swap(a[0],a[2]);
    swap(a[1],a[3]);

    Point A={(a[0].first+a[1].first)/2., (a[0].second+a[1].second)/2.};
    Point B={(a[2].first+a[3].first)/2., (a[2].second+a[3].second)/2.};
    // cerr<<A<<endl;
    // cerr<<B<<endl;

    double rA=sqrtl(1.*(a[0].first-a[1].first)*(a[0].first-a[1].first)+1.*(a[0].second-a[1].second)*(a[0].second-a[1].second))/2;
    // Point e=(B-A);
    // double dAB=sqrtl((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
    // e.x/=dAB;
    // e.y/=dAB;
    Point C=A;
    C.x+=rA/sq2 * (a[0].first<a[2].first ? 1:-1);
    C.y+=rA/sq2 * (a[0].second<a[2].second ? 1:-1);;

    // cerr<<C<<"\n";
    cout<<fixed<<setprecision(10) << abs(B.x-C.x)+abs(B.y-C.y) <<"\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}