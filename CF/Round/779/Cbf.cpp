#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
bool mark[N];
int arr[N];
int n,cnt;
int maxx=0,minn=100;
vector<vector<int>> ans[N];

int print(int l,int r){
    int pre=0,res=0;
    for(int i=l;i<=r;i++)
        if(arr[i]>pre) pre=arr[i],res++;
    // cout<<res<<' ';
    return res;
}

void bf(){
    int sum=0;
    vector<int> tmp;
    for(int i=1;i<=n;i++)
        arr[i+n]=arr[i];
    for(int i=n+1;i>=2;i--){
        int t=print(i,i+n);
        tmp.push_back(t);
        sum+=t;
    }
    ans[sum].push_back(tmp);
    // cout<<endl;
    // cout<<"SUM="<<sum<<endl;
    maxx=max(maxx,sum);
    minn=min(minn,sum);
}

void dfs(int deep){
    if(deep>n){
        bf();
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            arr[deep]=i;
            mark[i]=1;
            dfs(deep+1);
            mark[i]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    dfs(1);
    for(int i=n*2-1;i<=(n+1)*n/2;i++){
        cout<<i<<endl;
        sort(ans[i].begin(),ans[i].end());
        for(auto x:ans[i]){
            for(auto s:x) cout<<s<<' ';
            cout<<endl;
        }
        cout<<"-----"<<endl;
    }
    cout<<cnt<<endl;
    cout<<maxx<<' '<<minn<<endl;
    return 0;
}