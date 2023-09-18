#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#ifdef TRIPLE_XOR_SUM
#include "C:\Users\Administrator\Desktop\code\debug.cpp"
#else
#define debug(...) 1
#define debug_arr(...) 1
#endif

using ll = long long;
const int N = 1e6 + 10;
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

int dp[N];
int sq[N];
int tot;
vector<int> nxt;

//#include<random>
//#include<ctime>
//mt19937 rng(time(0));

int get(int n) {
	if(dp[n]!=-1)
		return dp[n];
	
	int t=sq[n];
//	tot+=t;
	
	nxt.clear();
	for(int k=(t*t==n); k<=t; ++k) {
		int cur=n-t*t+k*t;
		nxt.push_back(get(n-cur));
	}
	return dp[n]=mex(nxt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nxt.reserve(5010);
	sq[1]=1;
	for(int i=1; i<N; ++i) {
		if((sq[i-1]+1)*(sq[i-1]+1)==i) {
			sq[i]=sq[i-1]+1;
		}else {
			sq[i]=sq[i-1];
		}
	}
//	debug_arr(sq,1,100);
	memset(dp,-1,sizeof dp);
	
//	int up=1e6;
//	int nn=1e5;
//	for(int i=up-nn+1; i<=up; ++i) {
//		get(i);
//	}
//	debug(tot);

	for(int i=0; i<=100; ++i) {
		int re=get(i);
		cerr<<re<<" ";
	}
	exit(0);

	int n=1e5;
	int ans=0;
	cin>>n;
	for(int i=1,x; i<=n; ++i) {
//		x=rng()%int(1e6);
		cin>>x;
//		debug(x);
		ans^=get(x);
	}
	
//	debug(tot);
	
	cout<<(ans?"First":"Second");
 	return 0;
}
/*
2 
3 3


*/
