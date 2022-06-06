#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e4+10;
int fib[N];
set<int> st;

void fn(){
    fib[1]=fib[2]=1;
    for(int i=3;i<=1e3+10;i++){
        fib[i]=fib[i-1]+fib[i-2];
        st.insert(fib[i]);
    }
    st.insert(1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    fn();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) if(st.find(i)!=st.end()) cout<<'O'; else cout<<'o';
    return 0;
}