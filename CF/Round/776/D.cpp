#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e3+10;
int arr[N];

int shift(int x,int sz){
    int loc=0;
    for(int i=1;i<=sz;i++) if(arr[i]==x){
        loc=i;
        break;
    }
    vector<int> tmp;
    for(int i=loc+1;i<=sz;i++) tmp.push_back(arr[i]);
    for(int i=1;i<=loc;i++) tmp.push_back(arr[i]);
    for(int i=1;i<=sz;i++) arr[i]=tmp[i-1];
    return loc%sz;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> num,step;
        for(int i=1;i<=n;i++) cin>>arr[i],num.push_back(arr[i]);
        sort(num.begin(),num.end());
        while(num.size()){
            step.push_back(shift(num.back(),num.size()));
            num.pop_back();
        }
        reverse(step.begin(),step.end());
        for(auto x:step) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}