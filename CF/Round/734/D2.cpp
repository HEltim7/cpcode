#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=110;
char matrix[N][N];
int checkr[5]={0,0,1,-1};
int checkc[5]={0,-1,0,0};

void output(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j]==' '){
                for(char c='z';c>='a';c--){
                    bool flag=1;
                    for(int k=1;k<=3;k++){
                        if(matrix[i+checkr[k]][j+checkc[k]]==c) flag=0;
                    }
                    if(flag){
                        matrix[i][j]=c;
                        matrix[i+1][j]=c;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<matrix[i][j];
        cout<<endl;
    }
}


void fil(int i,int j){
    for(char c='a';c<='z';c++){
        bool flag=1;
        for(int k=1;k<=3;k++){
            if(matrix[i+checkr[k]][j+checkc[k]]==c) flag=0;
        }
        if(flag){
            matrix[i][j]=c;
            matrix[i][j+1]=c;
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) matrix[i][j]=' ';
        if(n%2==0&&m%2==0){
            if(k%2==0){
                cout<<"YES"<<endl;

                for(int j=1;j<=m;j+=2) for(int i=1;i<=n&&k;i++) fil(i,j),k--;
                output(n,m);
            }
            else cout<<"NO"<<endl;
        }
        else{
            if(n==1){
                if(k==n*m/2){
                    cout<<"YES"<<endl;

                    for(int j=1;j<=m;j+=2) for(int i=1;i<=n&&k;i++) fil(i,j),k--;
                    output(n,m);
                }
                else cout<<"NO"<<endl;
            }
            else if(m==1){
                if(k) cout<<"NO"<<endl;
                else{
                    cout<<"YES"<<endl;

                    output(n,m);
                }
            }
            else{
                if(m%2){
                    if(k%2||k*2>n*(m-1)) cout<<"NO"<<endl;
                    else{
                        cout<<"YES"<<endl;

                        for(int j=1;j<=m-1;j+=2) for(int i=1;i<=n&&k;i++) fil(i,j),k--;
                        output(n,m);
                    }
                }
                else{
                    if(k*2<m||(k-m/2)%2) cout<<"NO"<<endl;
                    else{
                        cout<<"YES"<<endl;

                        for(int j=1;j<=m;j+=2,k--) fil(1,j);
                        for(int j=1;j<=m;j+=2) for(int i=2;i<=n&&k;i++) fil(i,j),k--;
                        output(n,m);
                    }
                }
            }
        }
    }
    return 0;
}