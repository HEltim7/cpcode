#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
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
constexpr int K=1e3+10;
vector<int> cost[K];

void solve() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int k,w;
		cin>>k>>w;
		cost[k].emplace_back(w);
	}
	for(int i=0;i<K;i++) sort(cost[i].begin(),cost[i].end());
	
	int q;
	cin>>q;
	while(q--) {
		int t,h;
		cin>>t>>h;
		if(h==0) {
			cout<<0<<endl;
			continue;
		}
		
		vector<int> bit;
		while(h) {
			int hb=__lg(h);
			bit.emplace_back(hb+t);
			h-=1<<hb;
		}
		sort(bit.begin(),bit.end());
		
		int ans=0;
		multiset<int> pre;
		vector<int> cur;
		for(int i=0,j=0;i<K&&j<bit.size();i++) {
			cur.clear();
			int cnt=0,sum=0;
			for(int x:pre) {
				sum+=x;
				if(++cnt==2) {
					cur.emplace_back(sum);
					cnt=0;
					sum=0;
				}
			}
			
			pre.clear();
			for(int x:cur) pre.emplace(x);
			for(int x:cost[i]) pre.emplace(x);
			if(i==bit[j]) {
				if(pre.empty()) {
					ans=-1;
					break;
				}
				else {
					ans+=*pre.begin();
					pre.erase(pre.begin());
				}
				j++;
			}
		}
		cout<<ans<<endl;
	}	
}

/*
1
10 0
1
9 2

0

2
0 10000
1000 10000
4
1 0
1 1
0 1
1000 1

0
-1
10000
10000
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
