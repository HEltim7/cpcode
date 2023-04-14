#include <iostream>
using namespace std;

int matrix[10][10];

int main()
{
    int n,x,y,num;
    cin>>n;
    for(;;)
    {
        cin>>x>>y>>num;
        if (x==0&&y==0&&num==0)
        {
            break;
        }
        matrix[x][y]=num;
    }
    
}