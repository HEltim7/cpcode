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
            cin>>read[1][i][j];//z,y
            if(read[1][i][j]=='0') for(int k=1;k<=n;k++) mark[k][j][i]=1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            cin>>read[2][i][j];//x,z
            if(read[2][i][j]=='0') for(int k=1;k<=n;k++) mark[i][k][j]=1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            cin>>read[3][i][j];//y,x
            if(read[3][i][j]=='0') for(int k=1;k<=n;k++) mark[j][i][k]=1;
        }
    }
    //////////////////////////////
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         for(int k=1;k<=n;k++){
    //             cout<<"mark["<<i<<"]["<<j<<"]["<<k<<"]="<<mark[i][j][k]<<endl;
    //         }
    //     }
    // }
    //////////////////////////////
    for(int x=1;x<=3;x++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(read[x][i][j]=='1'){
                    bool ans=1;
                    if(x==1){
                        for(int k=1;k<=n;k++){
                            if(mark[k][j][i]==0){
                                ans=0;
                                break;
                            }
                        }
                    }
                    else if(x==2){
                        for(int k=1;k<=n;k++){
                            if(mark[i][k][j]==0){
                                ans=0;
                                break;
                            }
                        }
                    }
                    else{
                        for(int k=1;k<=n;k++){
                            if(mark[j][i][k]==0){
                                ans=0;
                                break;
                            }
                        }
                    }
                    if(ans){
                        cout<<"No";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Yes";
    return 0;
}