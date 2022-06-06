#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
int xyg[3010];
void getx(string s)
{
    int j=-1,l=s.length();
    for(int i=1; i<l; i++)
    {
        while(j!=-1&&s[i]!=s[j+1])
        {
            j=xyg[j];
        }
        if(s[i]==s[j+1])
            j++;
        if(j==-1||s[i+1]!=s[j+1])
            xyg[i]=j;
        else
            xyg[i]=xyg[j];
    }
}
int kmp(string s1,string s2)
{
    int jg=0,j=-1;
    int l1=s1.length(),l2=s2.length();
    for(int i=0; i<l1; i++)
    {
        if(j!=-1&&s1[i]!=s2[j+1])
            j=xyg[j];
        if(s1[i]==s2[j+1])
            j++;
        if(j==l2-1)
        {
            jg++;
            j=xyg[j];
        }
    }
    return jg;
}
int main()
{
    int n,jg;
    string s1,s2;
    scanf("%d",&n);
    getchar();
    getline(cin,s1);
    getx(s1);
    jg=0;
    for(int i=0; i<n; ++i)
    {
        getline(cin,s2);
        jg+=kmp(s2,s1);
    }
    printf("%d\n",jg);
    return 0;
}
 