#include <iostream>
#include <map>
using namespace std;

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

//int main() {
//	int arr[]={0,1,2,3,4,5};
//	debug_arr(arr,1,3);
//}

