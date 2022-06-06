#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=110;
string dabiao[25][N];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int len;
    cin>>len;
    int tmp=len/2+1;
    cout<<len*tmp-(len-len%2)*tmp/2<<endl;

    if(len>24){
        int firstr=(len+1)/2;//偏右
        for(int i=1;i<firstr;i++) cout<<'b';
        cout<<'r';
        for(int i=firstr+1;i<len;i++) cout<<'b';
        cout<<endl;

        firstr--;
        int col=(len+1)/2+1;
        int seconder=firstr+col;
        for(int i=1;i<=col;i++){
            int j;
            for(j=1;j<firstr;j++) cout<<'b';
            cout<<'r';
            j++;
            for(;j<=min(len,seconder-1);j++) cout<<'b';
            for(;j<=min(len,seconder+1);j++) cout<<'r';
            for(;j<=len;j++) cout<<'b';
            cout<<endl;
            seconder--;
        }
    }

}