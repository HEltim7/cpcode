#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 2e5 + 5;
const int M = 2e6 + 5;
int ts;
int n, k;
int num;
int nu[N];
bool cun[M];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> nu[i];
    cun[nu[i]] = 1;
  }
  int even = -2;
  int odd = -1;
  for (int i = 1; i <= k + k; i++) {
    if (i % 2) { // alice回合,删掉奇数
      odd += 2;
      while (cun[odd]) //如果遇到了在集合中出现过的，我直接把指针跳过
        odd += 2;
    } else { // bob回合，删掉偶数
      even += 2;
      while (cun[even])
        even += 2;
    }
  }
  //   cout << even << " " << odd << endl;
  odd += 2;
  while (cun[odd]) //如果遇到了在集合中出现过的，我直接把指针跳过
    odd += 2;
  even += 2;
  while (cun[even])
    even += 2;
  if (even > odd) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
  for (int i = 1; i <= n; i++) {
    cun[nu[i]] = 0;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> ts;
  while (ts--) {
    solve();
  }
  return 0;
}