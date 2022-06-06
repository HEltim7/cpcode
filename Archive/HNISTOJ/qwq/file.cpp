#include<iostream>
using namespace std;
FILE *fp;
string in;
char str[1000];
void fileopen(){
    if((fp=fopen("data.txt","a+"))==NULL){
        cout<<"file open failed"<<endl;
    }
    else{
        cout<<"file open success"<<endl;
    }
    return;
}

inline int read(){
    
}

int main()
{
    fileopen();   
    fscanf(fp,"%s",&str);
    cout<<str<<endl;
    //fprintf(fp,"%s",str);
    if(fclose(fp)!=EOF){
        cout<<"file close success"<<endl;
    }
    else{
        cout<<"file close failed"<<endl;
    }
    return 0;
}
