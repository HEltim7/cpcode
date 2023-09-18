#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<queue>
using namespace std;
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long double ld;
const ld eps=1e-8;
struct Point
{
	ld x,y;
	bool operator ==(const Point &a)const{
		return abs(x-a.x)<eps&&abs(y-a.y)<eps;
	}
	Point operator +(const Point &a)const{
		return {x+a.x,y+a.y};
	}
	
	Point operator -(const Point &a)const{
		return {x-a.x,y-a.y};
	}
	Point operator *(const ld &a)const{
		return {x*a,y*a};
	}
	Point operator /(const ld &a)const{
		return {x/a,y/a};
	}
	ld operator *(struct Point const &a)const{
		return x*a.x+y*a.y;
	}
	ld operator ^(struct Point const &a)const{
		return x*a.y-y*a.x;
	}
	ld len() const{
		return sqrt((*this)*(*this));
	}
	ld dis(Point &a)const{
		return ((*this)-a).len();
	}
	int toleft(const Point &a) const{
		auto t=(*this)^a;
		return (t>eps)-(t<-eps);
	}
};
bool argcmp(const Point &a,const Point &b){
	auto quad=[](const Point &a){
		if(a.y<-eps) return 1;
		if(a.y>eps) return 4;
		if(a.x<-eps) return 5;
		if(a.x>eps) return 3;
		return 2;
	};
	int qa=quad(a),qb=quad(b);
	if(qa!=qb) return qa<qb;
	auto t=a^b;
	return t>eps;
}
struct Line
{
	Point p,v;
	
	int toleft(const Point &a) const{
		v.toleft(a-p);
	}
	
	Point inter(const Line &a) const{
		return p+v*((a.v^(p-a.p))/(v^a.v));
	}
	bool operator <(const Line &a) const{
		if(abs(v^a.v)<=eps && v*a.v>=-eps) return toleft(a.p)==-1;
		return argcmp(v,a.v);
	}
};
struct Polygon
{
	vector<Point> p;
	int nxt(const int i) const{
		return i==p.size()-1?0:i+1;
	}
	int pre(const int i) const{
		return i==0?p.size()-1:i-1;
	}
	
	ld area() const{
		ld sum=0;
		for(int i=0;i<p.size();i++)
		{
//			debug(sum);
//			debug(p[i].x);
//			debug(p[i].y);
			sum+=p[i]^p[nxt(i)];
		}
		return sum;
	}
};
vector<Line> halfinter(vector<Line> l,const ld lim=1e9){
	const auto check=[](const Line &a,const Line &b,const Line &c){
		return a.toleft(b.inter(c))<0;//todo
	};
	
	l.push_back({{-lim,0},{0,-1}});
	l.push_back({{0,-lim},{1,0}});
	l.push_back({{lim,0},{0,1}});
	l.push_back({{0,lim},{-1,0}});
	
	sort(l.begin(),l.end());
	
	deque<Line> q;
	for(int i=0;i<l.size();i++)
	{
		if(i>0 && l[i-1].v.toleft(l[i].v)==0 && l[i-1].v*l[i].v>eps) continue;
		while (q.size()>1 && check(l[i],q.back(),q[q.size()-2])) q.pop_back();
		while (q.size()>1 && check(l[i],q[0],q[1]))q.pop_front();
		if(!q.empty() && q.back().v.toleft(l[i].v)<=0) return vector<Line> ();
		q.push_back(l[i]);
	}
	
	while(q.size()>1 && check(q[0],q.back(),q[q.size()-2])) q.pop_back();
	while(q.size()>1 && check(q.back(),q[0],q[1])) q.pop_front();
	return vector<Line>(q.begin(),q.end());
}
struct Convex: Polygon
{
	
};
Convex _halfinter(const vector<Line> &l,const ld lim=1e9){
	const auto lines=halfinter(l,lim);
	Convex C;
	C.p.resize(lines.size());
	if(lines.empty()) return C;
	for(int i=0;i<lines.size();i++)
	{
		const int j=(i==lines.size()-1?0:i+1);
		C.p[i]=lines[i].inter(lines[j]);
	}
	
	C.p.erase(unique(C.p.begin(),C.p.end()),C.p.end());
	if(C.p.front()==C.p.back()) C.p.pop_back();
	return C;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	Polygon vp;
	vp.p.resize(n);
	for(int i=0;i<n;i++)
	{
		scanf("%Lf%Lf",&vp.p[i].x,&vp.p[i].y);
	}

	ld w;
	scanf("%Lf",&w);

	Line line;
	scanf("%Lf%Lf",&line.p.x,&line.p.y);
	scanf("%Lf%Lf",&line.v.x,&line.v.y);
	line.v=line.v-line.p;

	vector<bool> vis(n);
	Polygon ver;
	ver.p.push_back(vp.p[0]);
	Point p=vp.p[0];
	vis[0]=true;
	while(ver.p.size()<n)
	{
		for(int i=0;i<n;i++)
		{
			if(vis[i]) continue;
			
			Line line={p,vp.p[i]-p};
			bool ok=true;
			for(int j=0;j<n;j++)
			{
				if(j==i) continue;
				
				debug(line.toleft(vp.p[j]));
				if(line.toleft(vp.p[j])<0)
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				vis[i]=true;
				debug(i);
				ver.p.push_back(vp.p[i]);
				p=vp.p[i];
				break;
			}
		}
	}
	
	vector<Line> lines;
	for(int i=0;i<n;i++)
	{
		debug(ver.p[i].x);
		debug(ver.p[i].y);
		lines.push_back({ver.p[i],ver.p[ver.nxt(i)]-ver.p[i]});
	}
	w/=2;
	line.v=line.v/line.v.len();
	auto sol=[&](vector<Line> lines,Line line,int t){
		debug(lines.size());
		if(t==0)
		{
			lines.push_back({line.p+Point{-line.v.y,line.v.x}*w,line.v});
			lines.push_back({line.p+Point{line.v.y,-line.v.x}*w,line.v*-1});
		}
		else
		{
			lines.push_back({line.p+Point{-line.v.y,line.v.x}*w,line.v*-1});
			lines.push_back({line.p+Point{line.v.y,-line.v.x}*w,line.v});
		}
		Convex C=_halfinter(lines);
	
		ld res=ver.area();
		ld ans=C.area();
		ans/=res;
		ans*=100;
		return ans;
	};
	ld res1=sol(lines,line,0);
	ld res2=sol(lines,line,1);
	ld res=max(res1,res2);
	printf("%.10Lf\n",res);
}
