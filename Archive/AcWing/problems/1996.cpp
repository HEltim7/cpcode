#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef vector<string> VS;
const int N=5e4+10;

int cnt[1<<7];
VS minn,maxx,str;

inline string getmin(string s){
    string res;
    for(auto x:s) cnt[x]++;
    for(char i='a';i<='z';i++)
        while(cnt[i]) res+=i,cnt[i]--;
    return res;
}

inline string getmax(string s){
    string res;
    for(auto x:s) cnt[x]++;
    for(char i='z';i>='a';i--)
        while(cnt[i]) res+=i,cnt[i]--;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string in;
        cin>>in;
        str.push_back(in);
        minn.push_back(getmin(in));
        maxx.push_back(getmax(in));
    }
    sort(minn.begin(),minn.end());
    sort(maxx.begin(),maxx.end());
    for(auto x:str){
        cout<<lower_bound(maxx.begin(),maxx.end(),getmin(x))-maxx.begin()+1<<' ';
        cout<<upper_bound(minn.begin(),minn.end(),getmax(x))-minn.begin()<<endl;
    }
    return 0;
}