#include<iostream>
using namespace std;

#define debug(x) cout << "[debug] " #x << " = " << x << endl
const int N=110;
bool mark[N][N][N];//x,y,z
char read[4][N][N];
bool white[4][N][N];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            cin>>read[1][i][j];
            if(read[1][i][j]=='0') for(int k=1;k<=n;k++) mark[k][j][i]=1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            cin>>read[2][i][j];
            if(read[2][i][j]=='0') for(int k=1;k<=n;k++) mark[i][k][j]=1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            cin>>read[3][i][j];
            if(read[3][i][j]=='0') for(int k=1;k<=n;k++) mark[j][i][k]=1;
        }
    }
    //////////////////////////////
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                cout<<"mark["<<i<<"]["<<j<<"]["<<k<<"]="<<mark[i][j][k]<<endl;
            }
        }
    }
    //////////////////////////////
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool res=1;
            for(int k=1;k<=n;k++) if(mark[k][i][j]==0){
                res=0;
                break;
            }
            white[1][i][j]=res;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool res=1;
            for(int k=1;k<=n;k++) if(mark[i][k][j]==0){
                res=0;
                break;
            }
            white[2][i][j]=res;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool res=1;
            for(int k=1;k<=n;k++) if(mark[i][j][k]==0){
                res=0;
                break;
            }
            white[3][i][j]=res;
        }
    }
    ///////////////////////////
    for(int k=1;k<=3;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(read[k][i][j]=='1'&&white[k][i][j]){
                    cout<<"NO";
                    return 0;
                }
            }
        }
    }
    cout<<"YES";
    return 0;
}