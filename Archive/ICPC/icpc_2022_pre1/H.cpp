#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define debug(x) \
    cerr<<string("[")+string(__func__)+string(" ")+to_string(__LINE__)+string("] ")\
    <<string(#x)+string(" = ")<<x<<endl;

const int mod=20220911;
ll dfs()
{
    ll cnt=0;
    while(1)
    {
        string s;
        cin>>s;
        if(s=="repeat")
        {
            cnt=(cnt+dfs())%mod;
        }
        else if(s=="for")
        {
            cin>>s;
            ll w=atoll(s.c_str());
            return cnt*w%mod;
        }
        else if(s=="library")
        {
            cnt++;
        }
        else if(s=="fin") return cnt;
    }


}
int main()
{
    cout<<dfs();
}