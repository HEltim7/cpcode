#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<iomanip>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=23333+10;

struct DATA {
    string name;
    double score[N]={0};
    DATA(string s) : name(s) {}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    unordered_map<string,int> ump,subs;
    vector<DATA> res;

    cout<<"Name";
    int n,idx=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string str,sub;
        double score;
        cin>>str>>sub>>score;
        if(!ump.count(str)){
            ump.emplace(str,idx++);
            res.push_back(DATA(str));
        }
        if(!subs.count(sub)) {
            subs.emplace(sub,cnt++);
            cout<<' '<<sub;
        }
        res[ump[str]].score[subs[sub]]=score;
    }

    cout<<endl;
    for(auto &[a,b]:res){
        cout<<a<<' ';
        for(int i=0;i<cnt;i++) 
            cout<<fixed<<setprecision(1)<<b[i]<<" \n"[i==cnt-1];
    }
    return 0;
}