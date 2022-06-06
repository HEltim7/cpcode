#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(student a,student b)
{
    return a.id>b.id;
}

struct student
{
    long long id;
    string name;
    int scr1;
    int scr2;
    int scr3;
}data[100];

int main()
{
    int ip;
    cin>>ip;
    for (int i = 0; i < ip+1; i++)
    {
        cin>>data[i].id>>data[i].name>>data[i].scr1>>data[i].scr2>>data[i].scr3;
    }

    //error
    for (int i = 0; i < ip+1; i++)
    {
        for (int j = 0; j < ip+1; j++)
        {
            if (data[i].id==data[j].id&&i!=j)
            {
                cout<<"error!";
                return 0;
            }
        }
    }
    
    //sort&output
    sort(data,data+ip+1,cmp);

    for (int i = 0; i < ip+1; i++)
    {
        cout<<data[i].id<<' '<<data[i].name<<' '<<data[i].scr1<<' '<<data[i].scr2<<' '<<data[i].scr3<<endl;
    }
    
    return 0;
}