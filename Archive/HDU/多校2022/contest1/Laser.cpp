#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'
using LL=long long;
using PII = pair<int,int>;
const int N=5e5+10;
const double eps=1e-8;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

namespace io {
    const int MAXBUF = 1e6, MAXLEN = 1e6;
    char buf[MAXBUF], *pl, *pr;
    char str[MAXLEN];

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T> T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        if (c != '.') return x = x * f;
        for (double t = 0.1; c = gc(), isdigit(c); t *= 0.1) x += (c - '0') * t;
        return x = x * f;
    }

    char* rd(char *p = str) {
        char c = gc(), *h = p;
        while (!isgraph(c)) c = gc();
        while (isgraph(c)) *p++ = c, c = gc();
        *p = '\0';
        return h;
    }

    char rd(char &c) {
        c = gc();
        while (!isgraph(c)) c = gc();
        return c;
    }

    string rd(string &s) { return s = rd(str); }

    // template<typename... T> void reads_impl(T&... x) { (rd(x),...); }

    #define read(x) io::rd(x)
    // #define reads(...) io::reads_impl(__VA_ARGS__)

    const int MAXPBUF = 1e6, PRECISION = 7;
    char pbuf[MAXPBUF], *pp = pbuf;

    void clear_buffer() { fwrite(pbuf, 1, pp-pbuf, stdout), pp = pbuf; }

    void push(const char &c) {
        if (pp - pbuf == MAXPBUF) clear_buffer();
        *pp++ = c;
    }

    template<typename T> void wt(T x) {
        if (x < 0) push('-'), x = -x;
        static int sta[40];
        int top = 0;
        do {
            sta[top++] = x % 10;
        } while (x/=10);
        while (top) push(sta[--top] + '0');
    }

    template<typename T> void wt_f(T x,int p) {
        if (x < 0) push('-'), x = -x;
        long long pre = (long long)x;
        wt(pre);
        x -= pre;
        if (p) push('.');
        while (p--) {
            x *= 10;
            int t = (int)x;
            x -= t;
            push(t + '0');
        }
    }

    void wt(const char &c) { push(c); }
    void wt(const string &s) { for (auto &x:s) push(x); }
    void wt(const char *p) { while (*p != '\0') push(*p++); }

    void wt(const float &x, int p = PRECISION) { wt_f(x,p); }
    void wt(const double &x, int p = PRECISION) { wt_f(x,p); }
    void wt(const long double &x, int p = PRECISION) { wt_f(x,p); }

    // template<typename... T> void writes_impl(const T&... x) { (wt(x),...); }

    #define write(...) io::wt(__VA_ARGS__)
    // #define writes(...) io::writes_impl(__VA_ARGS__)

    struct Exit {
        ~Exit() { clear_buffer(); }
    } static exit;
}

struct Point
{
    double x,y;

    bool operator ==(const Point &a) const {return abs(x-a.x)<eps&&abs(y-a.y)<eps;}
    Point operator +(const Point &a) const {return {x+a.x,y+a.y};}
    Point operator -(const Point &a) const {return {x-a.x,y-a.y};}
    Point operator -() const{return {-x,-y};}
    Point operator *(const double k) const {return {k*x,k*y};}
    Point operator /(const double k) const {return {x/k,y/k};}
    double operator *(const Point &a) const {return x*a.x+y*a.y;}//Dot
    double operator ^(const Point &a) const {return x*a.y-a.x*y;}//Cross
    bool operator <(const Point &a) const {if(abs(x-a.x)<eps) return y<a.y-eps; return x<a.x-eps;}
		bool is_par(const Point &a) const {return abs((*this)^a)<=eps;}
    bool is_ver(const Point &a) const {return abs((*this)*a)<=eps;}
    int toleft (const Point &a) const {auto t=(*this)^a; return (t>eps)-(t<-eps);}//在左侧为1
    double len2() const {return (*this)*(*this);}
    double dis2(const Point &a) const {return (a-(*this)).len2();}
    double len() const {return sqrt(len2());}//点到原点的距离
    double dis(const Point &a) const {return (a-(*this)).len();};//两点之间的距离
    double ang(const Point &a) const {return acos(((*this)*a)/(this->len()*a.len()));}//两个向量的夹角
    Point rot(const double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}//逆时针旋转rad°
} p[N];
struct Line
{
    Point p,v;

    bool operator ==(const Line &a) const {return p==a.p&&v==a.v;}
		bool is_par(const Line &a) const {return (v.is_par(a.v) && !v.is_par(p-a.p));}//平行且不重合为true
    bool is_ver(const Line &a) const {return v.is_ver(a.v);}//两条直线是否垂直
    bool is_on(const Point &a) const {return v.is_par(a-p);}//点是否在直线上
    int toleft(const Point &a) const {return v.toleft(a-p);}//点在直线向量方向的左侧为1，右侧为-1，直线上为0
    Point inter(const Line &a) const {return p+v*((a.v^(p-a.p))/(v^a.v));}//求两条直线的交点
    long double dis(const Point &a) const {return abs(v^(a-p)/v.len());}//点到直线的距离
    long double get_rad() const {return atan2(v.y,v.x);}
    Point proj(const Point &a) const {return p+v*((v*(a-p))/(v*v));}//点在向量v上的投影坐标
    double proj_len(const Point &a) const {return (v*a)/v.len();}//向量在向量v上的投影长度
};

vector<Point> get(Point &A,Point &B) {
    debug(A.x,A.y,B.x,B.y);
    vector<Point> res;
    double mx[]={0,1,1,-1};
    double my[]={1,1,0,1};
    Line la[4],lb[4];
    for(int i=0;i<4;i++) la[i]={A,{mx[i],my[i]}};
    for(int i=0;i<4;i++) lb[i]={B,{mx[i],my[i]}};
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(i!=j) {
                debug(la[i].p.x,la[i].p.y,la[i].v.x,la[i].v.y);
                debug(lb[j].p.x,lb[j].p.y,lb[j].v.x,lb[j].v.y);
                res.push_back(la[i].inter(lb[j]));
                debug(res.back().x,res.back().y);
            }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    return res;
}

bool check(Point &A,Point &B) {
    debug(A.x,A.y,A.x==B.x||A.y==B.y||abs(A.x-B.x)==abs(A.y-B.y));
    return A.x==B.x||A.y==B.y||abs(A.x-B.x)==abs(A.y-B.y);
}

void solve() {
    int n=read(n);
    for(int i=n;i>=1;i--) 
        read(p[i].x),read(p[i].y);
    if(n<=1) {
        write("YES\n");
        return;
    }
    Point A=p[1],B=p[2];
    int idx=2;
    while(check(A, B)&&idx<n) B=p[++idx];
    if(check(A, B)) {
        write("YES\n");
        return;
    }
    auto poi=get(A,B);
    bool ans=0;
    for(auto s:poi) {
        debug(s.x,s.y);
        bool cur=1;
        for(int i=1;i<=n;i++) if(!check(p[i], s)) {
            cur=0;
            break;
        }
        if(cur) {
            ans=1;
            break;
        }
    }
    write(ans?"YES\n":"NO\n");
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}