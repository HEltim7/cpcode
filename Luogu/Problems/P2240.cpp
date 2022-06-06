#include<bits/stdc++.h>
using namespace std;
struct gold_data
{
    int mass;
    int value;
    int vpm;
}gold[110];
bool cmp(gold_data a,gold_data b)
{
    return a.vpm>b.vpm;
}
int main()
{
    int n,t,maxx=0;
    cin>>n>>t;
    for (int i = 0; i < n; i++)
    {
        cin>>gold[i].mass>>gold[i].value;
        gold[i].vpm=gold[i].value/gold[i].mass;
    }
    sort(gold,gold+n,cmp);
    for(int i=0;t;i++)
        for(;t&&gold[i].mass;gold[i].mass--)
        {
            maxx+=gold[i].vpm;
            t--;
        }
    cout<<fixed<<setprecision(2)<<(double)maxx;
    return 0;
}