#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=1e5+10;
PII arr[N];
bool ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    set<int> st;
    for(int i=1;i<=n;i++) cin>>arr[i].first,arr[i].second=i,st.insert(arr[i].first);
    sort(arr+1,arr+1+n);
    for(int i=n;i>=1;i--){
        int id=arr[i].second;
        if(arr[i].first==arr[i+1].first) ans[id]=ans[arr[i+1].second];
        else{
            int p=k-(i-1);
            if(p>=3) ans[id]=0;
            else if(p==2){
                if(arr[i].first<arr[n].first/2) ans[id]=0;
                else if(arr[i].first*2<arr[i+1].first) ans[id]=0;
                else ans[id]=1;
            }
            else if(p<=1){
                if(arr[i].first*2>=arr[n].first/2) ans[id]=1;
                else if(n-i>=2){
                    auto it=st.lower_bound(arr[i].first*2+2);
                    it=prev(it);
                    if(*it*2>=arr[n].first) ans[id]=1;
                }
                else ans[id]=0;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}

/*

6 1
1 17 4 2 3 4

6 5
1 1 1 1 1 1

给非冠军选手使用道具？

3 1
3 6 13
1 1 1

3 1
3 7 14
1 1 1
*/