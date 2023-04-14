#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld eps=1e-8;

int sign(ld x)
{
    if(abs(x)<eps) return 0;
    if(x<0) return -1;
    return 1;
}
int cmp(ld x,ld y)
{
    if(abs(x-y)<eps) return 0;
    if(x<y) return -1;
    return 1;
}
struct Point
{
    ld x,y;
    bool operator == (const Point &a) const{
        return abs(x-a.x)<eps&&abs(y-a.y)<eps;
    }
    Point operator +(const Point &a) const{
        return {x+a.x,y+a.y};
    }
    Point operator -(const Point &a) const{
        return {x-a.x,y-a.y};
    }
    Point operator *(const Point &a) const{
        return {x*a.x,y*a.y};
    }
    Point operator *(const ld k) const{
        return {x*k,y*k};
    }
    ld operator ^(const Point &a) const{
        return x*a.y-a.x*y;
    }
    bool is_par(const Point &a) const{
        return abs((*this)^a)<=eps;
    }
};
struct Line 
{
    Point p,v;
    bool is_on(const Point &a) const{
        return v.is_par(a-p);
    }
};
struct Segment
{
    Point p1,p2;
};
bool on_segment(Point p,Segment s)
{
    return (p.x>min(s.p1.x,s.p2.x)-eps&&p.x<max(s.p1.x,s.p2.x)+eps&&
            p.y>min(s.p1.y,s.p2.y)-eps&&p.y<max(s.p1.y,s.p2.y)+eps);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<Point> a(n+1);
        for(int i=1;i<=n;i++)
        {
            scanf("%Lf%Lf",&a[i].x,&a[i].y);
        }
        if(n<5)
        {
            puts("NO");
            continue;
        }
        vector<Point> ver;
        ver.push_back(a[1]);
        ver.push_back(a[2]);
        Line line={a[1],a[1]-a[2]};

        int jishu=0;
        for(int i=3;i<=n;i++)
        {
            if(line.is_on(a[i]))
            {
                if(jishu<2) ver.push_back(a[i]),jishu++;
            }
            else
            {
                ver.push_back(a[i]);
            }
            if(ver.size()==5) break;
        }
        if(ver.size()!=5)
        {
            puts("NO");
        }
        else
        {
            bool gg=false;
            for(int i=0;i<ver.size();i++)//A
            {
                bool ok=true;
                
                for(int j=0;j<ver.size();j++)
                {
                    if(i==j) continue;
                    Line l={ver[i],ver[i]-ver[j]};
                    for(int k=0;k<ver.size();k++)
                    {
                        if(i!=k&&j!=k)
                        {
                            // cout<<i<<""<<j<<" "<<k<<endl;
                            if(l.is_on(ver[k])&&on_segment(ver[k], {ver[i],ver[j]})) ok=false;
                        }
                    }
                }
                if(ok)
                {
                    gg=true;
                    puts("YES");
                    printf("%.0Lf %.0Lf\n",ver[i].x,ver[i].y);
                    for(int j=0;j<ver.size();j++)
                    {
                        if(i==j) continue;
                        printf("%.0Lf %.0Lf\n",ver[j].x,ver[j].y);
                    }
                    break;
                }
            }
            if(!gg) puts("NO");
        
        }
    }
}