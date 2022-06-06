#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
const ll mo = 1e9 + 7;
ll a, b;
unordered_map<int,ll>zzz;
ll two=0, three=0, five=0;
ll x, y, z, ram, temp, mini;
ll ww, rr, ii;
vector<ll>nu;
ll mi(ll a, ll b) {
	ll ans = 1;
	a %= mo;
	while (b)
	{
		if (b & 1)ans = ans * a % mo;
		b >>= 1;
		a = a * a % mo;
	}
	return ans;
}
ll f(ll n) {
	ll res1 = (a + b)%mo;
	ll res2 = ((b-3*a)%mo+mo)%mo;
	if(n%2==0)
	return ((res1)*mi(3,n+1)%mo-3*res1+mo)%mo*(8,mo-2)%mo;
	else
	return (((res1)*mi(3,n+1)%mo-3*res1+mo)%mo+2*(res2)%mo*(8,mo-2)%mo)%mo;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	nu.reserve(1e6);
	bool xx = 0, yy = 0;
	cin >> x >> y >> z;
	nu.push_back(1);
	while ((!xx) || (!yy)) {
		if (nu.size() == x && !xx) {
			xx = 1;
			a = *nu.rbegin();
		}
		if (nu.size() == y && !yy) {
			yy = 1;
			b = *nu.rbegin();
		}
		ww = nu[two] * 2;
		rr = nu[three] * 3;
		ii = nu[five] * 5;
		mini = ww;
		mini = min(mini, rr);
		mini = min(mini, ii);
		if (mini == ww) {
			if (ww != *nu.rbegin()) {
				nu.push_back(ww);
			}
			two++;
		}
		else if (mini == rr){
			if (rr != *nu.rbegin()) {
				nu.push_back(rr);
			}
			three++;
		}
		else if (mini == ii) {
			if (ii != *nu.rbegin()) {
				nu.push_back(ii);
			}
			five++;
		}
	}
	cout << f(z) << endl;
	return 0;
}