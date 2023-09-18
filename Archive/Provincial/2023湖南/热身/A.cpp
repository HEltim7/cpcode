#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

__int128 ljh=1;
int main() {
	auto [x,y]=make_pair(1,2);
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		char c;
		scanf("%*[^#r]%c",&c);
//		printf("%c\n",c);
		if(c=='#') {
			int a,b,c;
			scanf("%02x%02x%02x",&a,&b,&c);
			printf("rgb(%d,%d,%d)\n",a,b,c);
		}else {
			int a,b,c;
			scanf("gb(%d,%d,%d)",&a,&b,&c);
			printf("#%02x%02x%02x\n",a,b,c);
		}
	}
	return 0;
} 
