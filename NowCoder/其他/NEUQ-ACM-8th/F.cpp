#include<iostream>
#include<algorithm>
using namespace std;
const long N=1010;
struct student_data{
    char name[30];
    char id[30];
    int grade;
    int sex;
} student[N];

bool cmp(student_data a,student_data b){
    if(a.grade!=b.grade)
        return a.grade<b.grade;
    return a.name<b.name;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%s%d%d%s",&student[i].name,&student[i].grade,&student[i].sex,&student[i].id);
    }
    sort(student,student+n,cmp);
    long q=0;
    int mth=0;
    char qname[30];
    cin>>q;
    for(long i=1;i<=q;i++){
        cin>>mth;
        if(mth==1){
            scanf("%s",&qname);
            
        }
    }
    return 0;
}