#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
vector<string> link[N];
map<string,int> st;
int idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        if(st.find(a)==st.end()){
            link[idx+1].push_back(a);
            link[idx+1].push_back(b);
            idx++;
            st.insert({b,idx});
        }
        else{
            int id=st[a];
            link[id].push_back(b);
            st.erase(a);
            st.insert({b,id});
        }
    }
    cout<<st.size()<<endl;
    for(auto [str,id]:st){
        cout<<link[id].front()<<' '<<link[id].back()<<endl;
    }
    return 0;
}