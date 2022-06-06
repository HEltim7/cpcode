#include<iostream>
using namespace std;

int main()
{
    int x,y,p;
    double q=0;
    cin>>x>>y;
    for (int p = x; p*p < y; p+=x)
    {
        q=y*1./p;
        if ((int)q!=q)
        {
            continue;
        }
        
    }
    
}