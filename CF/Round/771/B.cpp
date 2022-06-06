#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<int> odd,even;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            if(num[i]%2==0) even.push_back(num[i]);
            else odd.push_back(num[i]);
        }
        bool flag=1;
        for(int i=1;i<even.size();i++){
            if(even[i]<even[i-1]) flag=0;
        }
        for(int i=1;i<odd.size();i++){
            if(odd[i]<odd[i-1]) flag=0;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}