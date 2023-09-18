#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10,M=1e5+10;
int fa[N];
LL suma[N];
int sumc[N];
LL dp[M];

int findfa(int x) {
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}

bool join(int x,int y) {
	x=findfa(x);
	y=findfa(y);
	if(x==y) return false;
	fa[y]=x;
	suma[x]+=suma[y];
	sumc[x]+=sumc[y];
	return true;
}

void solve() {
	int n,m,v;
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++) cin>>suma[i];
	for(int i=1;i<=n;i++) cin>>sumc[i];
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		join(u,v);
	}
	
	vector<pair<int,LL>> vec;
	for(int i=1;i<=n;i++) 
		if(findfa(i)==i) {
			vec.emplace_back(sumc[i],suma[i]);
		}
	for(auto p:vec) {
		int c=p.first;
		LL a=p.second;
		for(int i=c;i<=v;i++) {
			dp[i]=max(dp[i],dp[i-c]+a);
		}
	}
	
	cout<<*max_element(dp,dp+M)<<endl;
}

/*
4 3 6
1 2 2 2
1 1 2 3
1 2
2 3
1 2

5
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
