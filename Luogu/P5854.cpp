#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

namespace fast_io {
    constexpr int MAXBUF = 1<<20;
    char buf[MAXBUF];

    char gc() {
        static char *pl=nullptr,*pr=nullptr;
        return (pl==pr&&(
            pr=(pl=buf)+fread(buf,1,MAXBUF,stdin),pl==pr
        )?EOF:*pl++);
    }

    template<typename T> T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        return x = x * f;
    }

    template<typename... T> auto read(T&... x) { return (rd(x),...); }   

    struct IO {
        template<typename T> friend IO&
        operator>>(IO &io, T& x) { rd(x); return io; }
    } static io;
}
using fast_io::io,fast_io::read;

template<typename T=int> struct CartesianTree {
	vector<int> lch,rch,stk;
	vector<T> val;
	int root,idx;

	void extend(int x) {
		idx++;
		lch.emplace_back(0);
		rch.emplace_back(0);
		val.emplace_back(x);
		
		while(stk.size()&&val[stk.back()]>x) {
			lch[idx]=stk.back();
			stk.pop_back();
		}
		if(stk.size()) rch[stk.back()]=idx;
		else root=idx;
		stk.emplace_back(idx);
	}

	void clear() {
		root=idx=0;
		lch.assign(1,{});
		rch.assign(1,{});
		val.assign(1,{});
		stk.clear();
	}

	CartesianTree(int sz=0) {
		lch.reserve(sz+1);
		rch.reserve(sz+1);
		val.reserve(sz+1);
		stk.reserve(sz+1);
		clear();
	}
};

void solve() {
    int n=read(n);
    CartesianTree<> tr(n);
    for(int i=1,in;i<=n;i++) tr.extend(read(in));
    LL l=0,r=0;
    for(int i=1;i<=n;i++) {
        l^=1LL*i*(tr.lch[i]+1);
        r^=1LL*i*(tr.rch[i]+1);
    }
    printf("%lld %lld",l,r);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    solve();
    return 0;
}