#include<iostream>
#include<map>
#include<set>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
map<string,int> s;

//res拿到这个局面的是谁,1=yes,0=no
void dfs(string ori,string str,int res){
    if(s.find(str)!=s.end()){
        s.insert({ori,res==s[str]});
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
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    s.insert({"0",0});
    s.insert({"1",1});
    set<string> pre,nex;
    pre.insert("0"),pre.insert("1");
    int t;
    cin>>t;
    while(t--){
        string in;
        cin>>in>>in;
        if(in.front()=='w'){
            bool flag=1;
            for(int i=1;i<in.size();i++) if(in[i]=='w'){
                flag=0;
                break;
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}