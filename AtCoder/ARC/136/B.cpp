#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
set<string> st;

inline void bf(char &a,char &b,char &c){
    char A=a,B=b,C=c;
    a=C,b=A,c=B;
}

void dfs(string cur){
    for(int i=0;i<cur.size()-2;i++){
        auto tmp=cur;
        bf(tmp[i],tmp[i+1],tmp[i+2]);
        if(st.find(tmp)==st.end()){
            st.insert(tmp);
            dfs(tmp);
        }
    }
}

inline int cal(string s){
    int res=0;
    for(int i=0;i<s.size()-1;i++)
        for(int j=i+1;j<s.size();j++)
            if(s[i]>s[j]) res++;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string in;
    cin>>in;
    st.insert(in);
    dfs(in);
    cout<<st.size()<<endl;
    for(auto x:st) cout<<x<<endl;

    for(auto x:st) cout<<cal(x)<<endl;
    return 0;
}