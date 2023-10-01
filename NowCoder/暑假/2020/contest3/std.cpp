#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

const int N=801000;
int n,m,pos[N],seq[N],ret[N],_;
int slot[N],used[N],ppos[N];
ll k;

void solve() {
	scanf("%d%d%lld",&n,&m,&k);
	rep(i,1,n+1) pos[i]=-1,seq[i]=-1;
	rep(i,1,n+1) scanf("%d",ret+i);
	int a=0;
	rep(i,1,n+1) {
		if (ret[i]<a) seq[i+m-1]=ret[i],pos[ret[i]]=i+m-1;
		else a=ret[i];
	}
	VI cnum,cpos;
	per(i,1,n+1) {
		if (pos[i]==-1) cnum.pb(i);
		if (seq[i]==-1) cpos.pb(i);
	}
	int l=SZ(cnum);
	unsigned long long way=1;
	rep(i,1,l+1) {
		way=way*min(i,m);
		if (way>k) {
			l=i;
			break;
		}
	}
	rep(i,l,SZ(cnum)) seq[cpos[i]]=cnum[i];
	cnum.resize(l); cpos.resize(l);
	reverse(all(cnum)); reverse(all(cpos));
	//rep(i,0,l) printf("%d ",cnum[i]); puts("num");
	//rep(i,0,l) printf("%d ",cpos[i]); puts("pos");
	rep(i,0,l) slot[i]=min(i+m,l)-i;
	rep(i,0,l) used[i]=0;
	rep(i,0,l) {
		unsigned long long totway=1;
		rep(j,0,l) if (!used[j]) totway=totway*slot[j];
		rep(j,0,l) {
			if (used[j]) continue;
			unsigned long long curway=totway;
			curway/=slot[j];
			//printf("pos %d num %d way %lld\n",i,j,curway);
			if (curway>=k) {
				used[j]=1;
				ppos[i]=j;
				rep(a,0,j) slot[a]-=1;
				break;
			}
			k-=curway;
			totway=totway/slot[j]*(slot[j]-1);
		}
	}
	rep(i,0,l) seq[cpos[i]]=cnum[ppos[i]];
	rep(i,1,n+1) printf("%d%c",seq[i]," \n"[i==n]);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}