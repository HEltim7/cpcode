#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e5+10;
int arr[N],pos[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    set<int> st;
    for(int i=1;i<=n;i++) {
        cin>>arr[i],pos[arr[i]]=i;
        if(arr[i]!=i) st.insert(i);
    }
    if(n<=2) {
        cout<<(is_sorted(arr+1,arr+1+n)?"YES":"NO")<<endl;
        return;
    }
    for(int i=1;i<=n;i++) {
        if(arr[i]!=i) {
            int aim=pos[i];
            int tmp;
            for(auto it=st.begin();;it=next(it)) {
                if(it==st.end()) {
                    cout<<"NO"<<endl;
                    return;
                }
                tmp=*it;
                if(tmp!=aim&&tmp!=i) break;
            }
            int x,y,z;
            if(tmp<aim) {
                x=arr[i],y=arr[tmp],z=arr[aim];
                arr[i]=z,arr[tmp]=x,arr[aim]=y;
                pos[z]=i,pos[x]=tmp,pos[y]=aim;
            }
            else {
                x=arr[i],y=arr[aim],z=arr[tmp];
                arr[i]=y,arr[aim]=z,arr[tmp]=x;
                pos[y]=i,pos[z]=aim,pos[x]=tmp;
            }
            st.erase(i);
            if(arr[aim]==aim) st.erase(aim);
            if(arr[tmp]==tmp) st.erase(tmp);
            debug(i,tmp,aim);
        }
        debug(arr,1,n);
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}