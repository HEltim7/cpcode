#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define debug(x) cout << "[debug] " << #x << " : " << x << endl
const int N = 100005;
int n;
double c;
double w[N];
double s[N];
double cmb[N];
double cmbsum;
void getcmb()
{
    cmb[0] = 1;
    cmb[n] = 1;
    for (int i = 1; i <= n + 1 >> 1; i++)
    {
        cmb[i] = cmb[i - 1] * (n - i + 1) / i;
        cmb[n - i] = cmb[i];
    }
    for (int i = 1; i <= n; i++)
        cmbsum += cmb[i];
    // for(int i=1;i<=n;i++) debug(i),debug(cmb[i]);
}
int main()
{
    double ans = 0;
    double sum = 0;
    scanf("%d%lf", &n, &c);

    getcmb();

    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &w[i]);
        s[i] = w[i] + s[i - 1];
    }

    sort(w + 1, w + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        s[i] = w[i] + s[i - 1];
    }

    for (int x = 0; x <= n; x++)
    {
        if (x == 0 || x == n)
            ans = c;
        else
            ans = c + ((x * 1.0 + (n - 1)) / 2) * ((s[n - 1] - s[x - 1]) / (n - 1 - x + 1));
        debug(x);
        debug(cmb[x]);
        ans = min(s[n], ans);
        //debug(cmbsum);
        sum += ans * cmb[x] / cmbsum;
    }

    printf("%.6lf", sum);
}