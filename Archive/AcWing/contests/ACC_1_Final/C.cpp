#include<bits/stdc++.h>
#ifndef debug
#define debug(args...)
#define debugArr(begin,end)
#endif
#define all(v) v.begin(),v.end()
#define fors(i,a,b) for(int i=(a);i<=(b);++i)
#define Case(T) int TTT;cin>>TTT;for(int T=1; T<=TTT; ++T)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
const int N=2e5+10;
int n;
vector<int>G[N];
int f[N];
unordered_set<ll> have;

inline ll get(int a,int b){
    return 1ll*a*N+b;
}

void dfs1(int u,int fa){
	for(int v:G[u])
	if(v!=fa){
		if(!have.count(get(u,v))) f[1]++;
		dfs1(v,u);
	}
}

void dfs(int u,int fa){
	if(u!=1){
		if(have.count(get(fa,u))) f[u]=f[fa]+1;
		else f[u]=f[fa]-1;
	}
	for(int v:G[u])
	if(v!=fa){
		dfs(v,u);
	}
}

int main() {
	cin>>n;
	for (int i=1,a,b; i<n; ++i){
		cin>>a>>b;
		have.insert(get(a,b));
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs1(1,0);
	dfs(1,0);
	//统计
	vector<int>ans;
	int fmin=1e9;
	for(int i=1; i<=n; ++i){
		if(f[i]==fmin) ans.push_back(i);
		else if(f[i]<fmin){
			ans.clear();
			ans.push_back(i);
			fmin=f[i];
		}
	}
	cout<<fmin<<'\n';
	for(int v:ans) cout<<v<<' ';
	return 0;
}