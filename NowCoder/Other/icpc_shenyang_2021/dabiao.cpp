#include <bits/stdc++.h>
#include <unordered_set>
#define endl '\n'
#define debug(x) cout << "[debug] " << #x << " : " << x << endl
using namespace std;
typedef long long ll;
typedef pair<int, string> pii;
vector<pii> nu;
int len;

void dfs(int step, string ps)
{
    if (step > len)
    {
        int sum = 0;
        int temp = 0;
        for (int i = 0; i < ps.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            { //j->i
                temp = 0;
                for (int k = j; k <= i; k++)
                {
                    if (ps[k] == 'r')
                    {
                        temp++;
                    }
                }
                if (temp & 1)
                {
                    sum++;
                }
            }
        }
        nu.push_back(pii(sum, ps));
        return;
    }
    dfs(step + 1, ps + 'b');
    dfs(step + 1, ps + 'r');
}

bool cmp(pii a, pii b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main()
{
    freopen("data.txt", "w+", stdout);
    for (len = 21; len <= 24; len++)
    {
        cout << "len " << len << ":" << endl;
        nu.clear();
        dfs(1, "");
        sort(nu.begin(), nu.end(), cmp);
        int maxi = nu[0].first;
        cout << maxi << endl;
        int i = 0;
        for (pii e : nu)
        {
            if (e.first == maxi && i < 100)
            {
                i++;
                cout << e.second << endl;
            }
            else
            {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}