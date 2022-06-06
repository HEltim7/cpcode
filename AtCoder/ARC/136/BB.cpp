#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=5e3+10;
int a[N],b[N];
int n;

inline int cal(int arr[]){
    int res=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(arr[i]>arr[j]) res++;
    return res%2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    vector<int> A,B;
    for(int i=1;i<=n;i++) cin>>a[i],A.push_back(a[i]);
    for(int i=1;i<=n;i++) cin>>b[i],B.push_back(b[i]);
    sort(A.begin(),A.end()),sort(B.begin(),B.end());
    
    bool flag=0;
    for(int i=0;i<B.size()-1;i++) if(B[i]==B[i+1]) flag=1;
    if(A!=B) cout<<"No";
    else if(flag) cout<<"Yes";
    else if(cal(a)!=cal(b)) cout<<"No";
    else cout<<"Yes";
    return 0;
}