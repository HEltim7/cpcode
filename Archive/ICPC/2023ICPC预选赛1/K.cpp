#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld eps=1e-8;
// const ll eps=0;
const int N=5003;
using _T=long double ;
template<typename T>struct point
{
    T x,y;

    bool operator ==(const point &a) const{
        return abs(x-a.x)<=eps&&abs(y-a.y)<=eps;
    }
    point operator +(const point &a) const{
        return {x+a.x,y+a.y};
    };
    point operator -(const point &a) const{
        return {x-a.x,y-a.y};
    };
    point operator *(const T &k) const{
        return {x*k,y*k};
    };
    point operator /(const T &k) const{
        return {x/k,y/k};
    };
    T operator *(const point &a) const{
        return x*a.x+y*a.y;
    };
    T operator ^(const point &a) const{
        return x*a.y-y*a.x;
    };

    T len2() const{
        return (*this)*(*this);
    }
    T len() const{
        return sqrt(len2());
    }
    T dis2(const point &a) const{
        return (a-(*this)).len2();
    }
    T dis(const point &a) const{
        return sqrt(dis2(a));
    }
    int toleft(const point &a) const {
        auto t=(*this)^a;
        return (t>eps)-(t<-eps);
    };

};
using Point=point<_T>;

template<typename T>struct line
{
    Point p,v;

    int toleft(const point<T> &a) const{
        return v.toleft(a-p);
    };
    ld dis(const point<T> &a) const{
        return abs(v^(a-p))/v.len();
    }
};
using Line=line<_T>;

template<typename T>struct segment
{
    point<T> a,b;

    ld dis(const point<T> &p) const{
        if((p-a)*(b-a)<-eps||(p-b)*(a-b)<-eps) return min(p.dis(a),p.dis(b));
        const line<T> l{a,b-a};
        return l.dis(p);
    }
};
using Segment=segment<_T>;

template<typename T>struct polygon
{
    vector<point<T>> p;

    int nxt(const int i) const {
        return i==p.size()-1?0:i+1;
    }
    int pre(const int i) const{
        return i==0?p.size()-1:i-1;
    }
};
using Convex=polygon<_T>;
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    Convex CC;
    CC.p.resize(n);
    for(auto &[x,y]:CC.p)
    {
        scanf("%Lf%Lf",&x,&y);
    }

    while(Q--)
    {
        Point p1,p2;
        scanf("%Lf%Lf",&p1.x,&p1.y);
        scanf("%Lf%Lf",&p2.x,&p2.y);

        Point mid=(p1+p2)/2;

        ld r2=mid.dis2(p1);

        Convex C=CC;

        for(auto &p:C.p)
        {
            p=p-mid;
        }

        Point zero={0,0};
        bool ok=true;
        for(int i=0;i<C.p.size();i++)
        {
            Line line={C.p[i],C.p[C.nxt(i)]-C.p[i]};
            if(line.toleft(zero)==-1)
            {
                ok=false;
                break;
            }
        }
        ld res=r2/2;
        if(!ok)
        {
            ld mini=4E18;
            for(int i=0;i<C.p.size();i++)
            {
                Segment seg={C.p[i],C.p[C.nxt(i)]};
                ld ans=seg.dis(zero);
                mini=min(mini,ans);
            }
            res=res+mini*mini;
        }
        printf("%.10Lf\n",res);
    }
}