#include<iostream>
#include<algorithm>
#include<string.h>
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

const int N=200005,M=11;
char L[N],R[N];
int n;
int dp[M][N][M];
bool vis[M],vis2[M];
int dif=0;
int dif2=0;
int A;
const int mod=1e9+7;
int c[M][M];
int main()
{
	scanf("%d",&n);
	scanf("%s",L+1);
	scanf("%s",R+1);
	scanf("%d",&A);
//	c[0][0]=1;
//	for(int i=1;i<M;i++)
//		for(int j=0;j<M;j++)
//			if(!j) c[i][j]=1;
//			else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
			
	auto update=[&](char c){
		int w=c-'0';
		if(vis[w]) return ;
		vis[w]=true;
		dif++;
	};
	auto update2=[&](char c){
		int w=c-'0';
		if(vis2[w]) return ;
		vis2[w]=true;
		dif2++;
	};

	int cur=1;
	while(cur<=n&&L[cur]==R[cur])
	{
		update(L[cur]);
		cur++;
	}

	if(dif>A)
	{
		puts("0");
		return 0;
	}
	
	if(cur==n+1)
	{
		if(dif==A) puts("1");
		else puts("0");
		return 0;
	}
	
	for(int k=0;k<=A;k++)//must add
	{
		dp[k][0][0]=1;
		int may=A-k;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				dp[k][i+1][j]=(dp[k][i+1][j]+1ll*dp[k][i][j]*(may+j))%mod;
				if(j<k) dp[k][i+1][j+1]=(dp[k][i+1][j+1]+1ll*dp[k][i][j]*(10-(may+j)))%mod;
			}
		}
	}
	int res=0;
	for(int i=0;i<10;i++) vis2[i]=vis[i];
	dif2=dif;
	//L is l
	//枚举当前贴着L的什么时候不贴着 
	update2(L[cur]);
	for(int i=cur+1;i<=n;i++)
	{
		//不妨cur is L[]
		 for(int j=L[i]-'0'+1;j<10;j++)
		 {
		 	int dif3=dif2+(!vis2[j]);
		 	if(A>=dif3)
		 	{
		 		res=(res+1ll*dp[A-dif3][n-i][A-dif3])%mod;
			 }
		 }
		 update2(L[i]);
	}
//	debug(res);
	if(dif2==A) res=(res+1)%mod;
	
//	debug(res);
	for(int i=0;i<10;i++) vis2[i]=vis[i];
	dif2=dif;
	update2(R[cur]);
	for(int i=cur+1;i<=n;i++)
	{
		for(int j=R[i]-'0'-1;j>=0;j--)
		{
			int dif3=dif2+(!vis2[j]);
			if(A>=dif3)
			{
//				debug(dp[A-dif3][n-i][A-dif3]);
				res=(res+dp[A-dif3][n-i][A-dif3])%mod;
			}
		}
		update2(R[i]);
	}
	if(dif2==A) res=(res+1)%mod;
//	debug(res);
	for(int i=0;i<10;i++) vis2[i]=vis[i];
	dif2=dif;
	for(int j=L[cur]-'0'+1;j<=R[cur]-'0'-1;j++)
	{
		int dif3=dif2+(!vis2[j]);
		if(A>=dif3) res=(res+dp[A-dif3][n-cur][A-dif3])%mod;
	}
	printf("%d\n",res);
	return 0;
}
/*
2
40
77
2

34


3
101
343
1

3

3
111
333
1
*/
