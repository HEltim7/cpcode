#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
vector<int> num;

void init(){
    for(int i=1;i<=13;i++)
        num.push_back(1<<i);
    for(int i=1,cnt=1;i<=7;i++){
        cnt*=i;
        num.push_back(cnt);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
}

int dfs(int aim,int now,int step,int deep){
    if(now==aim) return step;
    int res=1000;
    for(int i=deep;i<num.size();i++){
        if(now+num[i]>aim) continue;
        res=min(res,dfs(aim,now+num[i],step+1,i+1));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    // for(int i=150;i<=200;i++){
    //     cout<<i<<endl;
    // }
    // for(int i=150;i<=200;i++)
    //     cout<<dfs(i,0,0,0)<<endl;
    cout<<dfs(185,0,0,0);
    return 0;
}