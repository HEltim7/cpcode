#include<iostream>
using namespace std;

#define endl '\n'

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    string s;
    string q,w,e,r;
    cin>>s;
    int level=0;
    for(auto i:s){
        if(i>='a'&&i<='z') q+=i;
        else if(i>='A'&&i<='Z') w+=i;
        else if(i>='0'&&i<='9') e+=i;
        else r+=i;
    }
    if(q.size()) level++;
    if(w.size()) level++;
    if(e.size()) level++;
    if(r.size()) level++;
    cout<<"password level:"<<level<<endl;
    if(q.empty()) cout<<"(Null)"<<endl;
    else cout<<q<<endl;
    if(w.empty()) cout<<"(Null)"<<endl;
    else cout<<w<<endl;
    if(e.empty()) cout<<"(Null)"<<endl;
    else cout<<e<<endl;
    if(r.empty()) cout<<"(Null)"<<endl;
    else cout<<r<<endl;
    return 0;
}