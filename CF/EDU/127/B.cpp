#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define cat(...)
#define cat_arr(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<int> arr;
        cin>>n;
        int two=0,one=0;
        bool ans=1;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            if(i>1){
                if(in-arr.back()==1) ;
                else if(in-arr.back()==2) one++;
                else if(in-arr.back()==3) two++;
                else ans=0;
                cat(i,in,one);
            }
            arr.push_back(in);
        }
        cat(one,two);
        if(two&&one) ans=0;
        if(two>=2) ans=0;
        if(one>=3) ans=0;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}