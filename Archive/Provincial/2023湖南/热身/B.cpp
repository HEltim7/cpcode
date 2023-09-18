#include <iostream>
#include <vector>
using namespace std;

void solve()
{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	s=" "+s;
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=min(l,r);i<=max(l,r);i++)
	{
		printf("%c",s[i]);
	}
	cout<<endl;
}

int main() {
	int t=1;
	while(t--) solve();
}

