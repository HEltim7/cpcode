#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, k;
int nu[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> nu[i];
    if (nu[i] < k) {
      cout << "Python 3." << i << " will be faster than C++" << endl;
      return 0;
    }
  }
  for (int i = n + 1; i < MAXN; i++) {
    nu[i] = max(0, nu[i - 1] + nu[i - 1] - nu[i - 2]);
    if (nu[i] < k) {
      cout << "Python 3." << i << " will be faster than C++" << endl;
      return 0;
    }
  }
  cout << "Python will never be faster than C++" << endl;
  return 0;
}