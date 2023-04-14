#include<iostream>
using namespace std;
int n;

int main(){
    cin>>n;
    string str;
    for(int i=1;i<=n;i++) str+='o';
    for(int i=1;i<=n;i++) str+='*';
    str+="--";
    cout<<str<<endl;
    
    while(n>3){
        swap(str[n-1],str[2*n]);
        swap(str[n],str[2*n+1]);
        cout<<str<<endl;
        if(n!=4){
            swap(str[n-1],str[2*(n-1)]);
            swap(str[n],str[2*(n-1)+1]);
            cout<<str<<endl;
        }
        n--;
    }
    swap(str[3],str[7]);
    swap(str[4],str[8]);
    cout<<str<<endl;
    swap(str[1],str[7]);
    swap(str[2],str[8]);
    cout<<str<<endl;
    swap(str[1],str[6]);
    swap(str[2],str[7]);
    cout<<str<<endl;
    swap(str[0],str[6]);
    swap(str[1],str[7]);
    cout<<str<<endl;
    return 0;    
}