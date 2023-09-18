#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
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
const int N = 2e5 + 10;
int mex(const vector<int>& a) {
	vector<int> vis(a.size()+1);
	for(int x:a) {
		if(x<vis.size())
			vis[x]=1;
	}
	int id=0;
	while(vis[id])
		id++;
	return id;
}

int main() {
	int n=1000000;
	vector<int> g(n+1);
	int t=0;
	for(int i=1; i<=n; ++i) {
		int sq=sqrt(i+0.5);
		t+=sq;
		int k=(sq*sq==i);
		vector<int> nxt;
		while(k<=sq) {
			int cur=i-sq*sq+k*sq;
			nxt.push_back(g[i-cur]);
			++k;
		}
		g[i]=mex(nxt);
	}
	debug(t);
//	debug(g);
 	return 0;
}
