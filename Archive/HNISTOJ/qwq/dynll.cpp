//对接c教材（动态）链表
#include<iostream>
#include<stdlib.h>
#define LEN sizeof(struct node)
using namespace std;

typedef struct node poi;

struct node
{
    int data;
    poi *next;
}*head;

poi *fn()
{
    poi *h,*p,*q;
    int n;
    h=(poi*)(calloc(1,LEN));
    p=h;
    cin>>n;
    while (n!=-1)
    {
        q=(poi*)(calloc(1,LEN));
        q->data=n;
        p->next=q;
        p=q;
        cin>>n;
    }
    p->next=NULL;
    return h;
}

int main()
{
    head=fn();
    while (head->next!=NULL)
    {
        head=head->next;
        cout<<head->data<<' ';
    }
    return 0;
}