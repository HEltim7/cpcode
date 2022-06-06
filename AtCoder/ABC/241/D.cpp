#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    multiset<LL> st;
    int q;
    cin>>q;
    while (q--)
    {
        LL op,x,k;
        cin>>op>>x;
        if(op!=1) cin>>k;
        if(op==1) st.insert(x);
        else if(op==2){
            auto it=st.upper_bound(x);
            bool flag=1;
            for(int i=1;i<=k;i++){
                if(it!=st.begin()) it=prev(it);
                else {
                    flag=0;
                    break;
                }
            }
            if(flag) cout<<*it<<endl;
            else cout<<-1<<endl;
        }
        else{
            auto it=st.lower_bound(x);
            k--;
            bool flag=1;
            for(int i=1;i<=k;i++){
                if(it!=st.end()) it=next(it);
                else{
                    flag=0;
                    break;
                }
            }
            if(!flag||it==st.end()) cout<<-1<<endl;
            else cout<<*it<<endl;
        }
    }
    return 0;
}