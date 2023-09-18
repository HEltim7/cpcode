#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

#ifdef TRIPLE_XOR_SUM
namespace debug {
	using S=string;
	using std::to_string;
	
	S to_string(const char &x) {
		return S(1,x);
	}
	S to_string(const string &x) {
		return "\""+x+"\"";
	}
	S to_string(const bool &x) {
		return x?"true":"false";
	}
	
	template<typename T,typename U> S to_string(const pair<T,U> &x) {
		return "("+to_string(x.first)+","+to_string(x.second)+")";
	}
	
	template<typename T> S to_string(const T& x) {
		S res="{";
		for(auto &i:x) res+=to_string(i),res+=",";
		res.back()='}';
		return res;
	}
	
	template<typename T> S _get(const T& x) {
		return to_string(x);
	}
	
	template<typename T,typename... U> S _get(const T& x,const U&... y) {
		return to_string(x)+" | "+_get(y...);
	}
	
	template<typename... T> S get(S name,const T&... x) {
		return name+" = "+_get(x...);
	}
	
	template<typename T> S geta(S name,const T& arr,int l,int r) {
		S res=name+"["+to_string(l)+"->"+to_string(r)+"] = [";
		for(int i=l;i<=r;i++) res+=to_string(arr[i])+",";
		res.back()=']';
		return res;
	}
}
#define __pos__ string{}+"["+__func__+" "+to_string(__LINE__)+"] "
#define debug(...) cerr<<debug::get(__pos__+#__VA_ARGS__,__VA_ARGS__)<<endl
#define debug_arr(x,l,r) cerr<<debug::geta(__pos__+#x,x,l,r)<<endl
#else
#define debug(...) 1
#define debug_arr(...) 1
#endif

using ll = long long;
const int N = 400 + 10;
const int inf = 0x3f3f3f3f;
int g[N][N];
int mc[N][N];

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> s(n),t(n);
	for(int& x:s) cin>>x;
	for(int& x:t) cin>>x;
//	debug(s);
	
	memset(g,inf,sizeof g);
	while(m--) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=min(g[u][v],w);
	}
	
	for(int i=1; i<=400; ++i) {
		g[i][i]=0;
	}
	
	for(int k=1; k<=400; ++k) {
		for(int i=1; i<=400; ++i) {
			for(int j=1; j<=400; ++j) {
				if(i!=j && j!=k && i!=k) {
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
	}
	
	memset(mc,inf,sizeof mc);
	for(int i=1; i<=400; ++i) {
		for(int j=1; j<=400; ++j) {
			for(int h=1; h<=400; ++h) {
				mc[i][j]=min(mc[i][j],g[i][h]+g[j][h]);
			}
		}
	}
	
	int res=inf;
	for(int i=0; i<n; ++i) {
		int cur=0;
		bool ok=1;
		for(int j=0; j<n; ++j) {
			int a=s[(i+j)%n];
			int b=t[j];
			if(a==b) continue;
			if(a<1 || a>400|| b<1 || b>400 || mc[a][b]==inf) {
				ok=0;
				break;
			}
			cur+=mc[a][b];
		}
		if(ok)
			res=min(res,cur);
	}
	if(res==inf) {
		cout<<-1;
	}else {
		cout<<res;
	}
 	return 0;
}
/*
4 3
1 2 3 4
1 5 5 4
2 5 8
5 3 13
4 6 3

ans:21

4 4
1 2 3 4
1 5 5 4
2 5 8
5 3 13
2 100 1
100 5 1


*/
