#include<iostream>
using namespace std;
///////////////////////////////////
struct el{
    int fa;
    int number;
    string name;
}man[10010];

int getfa(el in){
    if(in.fa==in.number){return in.number;}
    return in.fa=getfa(in);
}

int main(){
    int a,sum=0,k;
    string in,head,tail;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>in;
        head="";
        tail="";
        for(int j=0;j<in.length();j++){
            if(in[j]=='%'){
                for(j++;j<in.length();j++){
                    tail+=in[j];
                }
                break;
            }
            head+=in[j];
        }
        //////////////////////////
        for(k=1;k<=sum+1;k++){
            if(man[k].name==head){
                for(int q=1;q<=sum+1;q++){
                    if(man[q].name==tail){
                        man[k].fa=getfa(man[q]);
                        break;
                    }
                    else if(q>sum){
                        man[++sum].number=sum;
                        man[sum].fa=sum;
                        man[sum].name=tail;
                        man[k].fa=getfa(man[q]);
                        break;
                    }
                }
                break;
            }
            else if(k>sum){
                man[++sum].number=sum;
                man[sum].fa=sum;
                man[sum].name=head;
                for(int q=1;q<=sum+1;q++){
                    if(man[q].name==tail){
                        man[k].fa=getfa(man[q]);
                        break;
                    }
                    else if(q>sum){
                        man[++sum].number=sum;
                        man[sum].fa=sum;
                        man[sum].name=tail;
                        man[k].fa=getfa(man[q]);
                        break;
                    }
                }
                break;
            }
        }
        cout<<man[man[k].fa].name<<endl;
    }
    return 0;
}