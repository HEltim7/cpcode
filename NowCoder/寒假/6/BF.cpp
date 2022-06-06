#include<iostream>
#include<map>
#include<set>
using namespace std;

// #define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
map<string,int> s;

//res拿到这个局面的是谁,1=yes,0=no
void dfs(string ori,string str,int res){
    if(s.find(str)!=s.end()){
        bool flag=0;
        if(s.find(ori)!=s.end()) flag=s[ori];
        s.insert({ori,max(flag,res==s[str])});
        if(s["ori"]) cout<<ori<<' '<<"Yes"<<endl;
        else cout<<ori<<' '<<"No"<<endl;
        return;
    }
    if(str.front()=='1'){
        str.front()='0';
        dfs(ori,str,res^1);
        str.front()='1';
    }
    for(int i=0;i<str.size()-1;i++)
        for(int j=i+1;j<str.size();j++){
            string bak=str;
            if(str[j]=='1'){
                str[j]='0';
                if(str[i]=='1') str[i]='0';
                else str[i]='1';
                while(str.back()=='0'&&str.size()>=2) str.pop_back();
                dfs(ori,str,res^1);
                str=bak;
            }
        }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    s.insert({"0",0});
    s.insert({"1",1});
    set<string> pre,nex;
    pre.insert("0"),pre.insert("1");
    for(int i=2;i<=5;i++){
        for(auto x:pre){
            dfs(x+'1',x+'1',1);
            dfs(x+'0',x+'0',1);
            nex.insert(x+'0');
            nex.insert(x+'1');
        }
        pre=nex;
        nex.clear();
    }
    return 0;
}