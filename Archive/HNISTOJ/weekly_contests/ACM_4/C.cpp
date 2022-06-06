//树遍历
#include<iostream>
using namespace std;
long t,pear,plate,way=1;
long data[10];

void fn(long main)
{
    data[main]--;
    data[main+1]++;
    if(data[main]<data[main+1])
    {
        data[main]++;
        data[main+1]--;
        return;
    }
    else
    {
        way++;
        for(int i=main;i<plate;i++)
        {
            fn(i);
        }
            data[main]++;
            data[main+1]--;
    }
}

int main()
{
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>pear>>plate;
        data[1]=pear;
        for(int i=2;i<=plate;i++){
            data[i]=0;
        }
        fn(1);
        cout<<way<<endl;
        way=1;
    }
    return 0;
}