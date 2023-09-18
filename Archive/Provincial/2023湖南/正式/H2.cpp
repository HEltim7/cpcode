#include <algorithm>
#include <iostream>
#include <vector>
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
constexpr int N=2e5+10,W=1e6+10;
int cnt[W];
vector<int> group[W];

void solve() {
	int n;
	cin>>n;
	LL ans=0;
	
	auto add_val=[&](int gc) {
		if(cnt[gc]+1==2) return 2*gc;
		else if(cnt[gc]+1>2) return gc;
		else return 0;
	};
	
	auto sub_val=[&](int gc) {
		if(cnt[gc]-1==1) return -2*gc;
		else if(cnt[gc]-1>1) return -gc;
		return 0;
	};
	
	auto add=[&](int gc) {
		ans+=add_val(gc);
		cnt[gc]++;
	};
	
	auto sub=[&](int gc) {
		ans+=sub_val(gc);
		cnt[gc]--;
	};

	for(int i=1;i<=n;i++) {
		int in;
		cin>>in;
		group[in].emplace_back(in);
		add(in);
	}

	for(int i=W-1;i>=1;i--) {
		for(int j=2;i*j<W;j++) {
			int k=i*j;
			if(group[k].size()==1) {
				int gc=group[k][0];
				if(gc!=i&&cnt[gc]==1) {
					group[k][0]=i;
					sub(gc);
					add(i);
				}
			}
		}
		if(group[i].size()) debug(i,group[i],ans);
	}
	
	cout<<ans<<endl;
}

/*
4
3 2 3 4

ans=10

6
2 2 2 7 7 7
ans=27

2
6 8
ans=4

4
12 4 4 3
ans=14

5
2 2 4 6 10
ans=10;
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
