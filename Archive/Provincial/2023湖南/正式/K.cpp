#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
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

#define endl '\n'
using LL=long long;
constexpr int N=22,mod=1e9+9;

using Mat=array<array<int,N>,N>;
Mat bak{};

Mat mul(Mat x,Mat y) {
	Mat res{};
	for(int i=1;i<N;i++) {
		for(int k=1;k<N;k++) {
			if(x[i][k]==0) continue;
			for(int j=1;j<N;j++) {
				res[i][j]=(res[i][j]+1LL*x[i][k]*y[k][j]%mod)%mod;
			}
		}
	}
	return res;
}

Mat qpow(Mat x,int k) {
	Mat res{};
	for(int i=1;i<N;i++) res[i][i]=1;
	while(k) {
		if(k&1) {
			res=mul(res,x);
		}
		k>>=1;
		x=mul(x,x);
	}
	return res;
}

void solve() {
	int n,m,k,d;
	cin>>n>>m>>k>>d;
	vector<int> pos(k);
	for(int &x:pos) cin>>x;
	for(int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		bak[u][v]++;
		bak[v][u]++;
	}
	auto sol=[&](int st) {
		Mat cur=bak;
		Mat res{};
		for(int i=1;i<=n;i++) res[1][i]=1;
		for(int i=0;i<k;i++) {
			if(st>>i&1) continue;
			int u=pos[i];
			res[1][u]=0;
			for(int v=1;v<=n;v++) cur[u][v]=cur[v][u]=0;
		}
		cur=qpow(cur,d-1);
		res=mul(res,cur);
		int ans=0;
		for(int i=1;i<=n;i++) ans=(ans+res[1][i])%mod;
		return ans;
	};
	
	int ans=0;
	for(int i=0;i<1<<k;i++) {
		int res=sol(i);
//		debug(i,sol(i));
		int b=__builtin_popcount(i);
		if((k-b)&1) ans=(ans-res+mod)%mod;
		else ans=(ans+res)%mod;
	}
	cout<<ans<<endl;
}

/*
4 4 2 3
1 2
1 2
2 3
3 1
2 4

10
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
