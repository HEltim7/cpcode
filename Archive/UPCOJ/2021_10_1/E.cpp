#include<iostream>
#include<stack>
using namespace std;

const int N=1e5+10;
int n;
int arr[N];
int ans[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    stack<int> st;
    for(int i=1;i<=n;i++){
        while(!st.empty()&&st.top()<arr[i]) st.pop();
        ans[i]+=st.size();
        st.push(arr[i]);
    }
    while(st.size()) st.pop();
    for(int i=n;i>=1;i--){
        while(!st.empty()&&st.top()<arr[i]) st.pop();
        ans[i]+=st.size();
        st.push(arr[i]);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}