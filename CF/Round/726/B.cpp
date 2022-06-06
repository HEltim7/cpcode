#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ts;
ll x, y, n, m;
const ll mx = -0x3f3f3f3f3f3f3f;
struct node
{
	ll xx1;
	ll yy1;
	ll xx2;
	ll yy2;
	ll p;
};
bool cmp(node a, node b) {
	return a.p > b.p;
}
vector<node>nu;
int main() {
	scanf("%lld", &ts);
	while (ts--)
	{
		nu.clear();
		scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
		nu.push_back({ 1,m,1,1,(llabs(y - m) + llabs(x-1)+llabs(y-1))*2 });
		nu.push_back({ n,1,1,1,(llabs(y - 1) + llabs(x - n) + llabs(x - 1)) * 2 });
		nu.push_back({ 1,m,n,m ,(llabs(y - m) + llabs(x - 1) + llabs(x - n)) * 2 });
		nu.push_back({ n,1,n,m,(llabs(y - 1) + llabs(x - n) + llabs(y - m)) * 2 });

		nu.push_back({ 1,1,n,m,(llabs(x-1)+llabs(y-1)+llabs(x-n)+llabs(y-m))*2 });
		nu.push_back({ n,1,1,m,(llabs(x-n)+llabs(y-1)+llabs(x-1)+llabs(y-m))*2 });

		sort(nu.begin(), nu.end(), cmp);
		printf("%lld %lld %lld %lld\n", nu[0].xx1, nu[0].yy1, nu[0].xx2, nu[0].yy2);
	}


	return 0;
}
