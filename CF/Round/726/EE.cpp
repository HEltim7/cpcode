#include<bits/stdc++.h>
using namespace std;
char s[(int)1e6 + 5];
int len, k;
int main() {
	scanf("%d%d", &len, &k);
	scanf("%s", s);
	putchar(s[0]);
	int j = 0;
	for (int i = 1;i < k;i++) {
		if (i == len) {
			len *= 2;
			for (int x = i ;x < len ;x++) {
				s[x] = s[x - i];
			}
		}
		if (strcmp(s + i, s) < 0 && strcmp(s + i, s + j) < 0) {
			putchar(s[i]);
			continue;
		}
		if (strcmp(s,s+i)<0 && strcmp(s,s+j)<0) {
			j = 0;
			s[i] = s[0];
			putchar(s[i]);
			continue;
		}
		if (strcmp(s+j, s + i) <= 0 && strcmp(s+j, s) <= 0) {
			s[i] = s[j];
			putchar(s[i]);
			j++;
			continue;
		}
	}
	
	return 0;
}