#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
node* head;
node* tail;
struct node* creNode(int x)
{
    node* p= new node;
    p->data=x;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void InsHead(int x)
{
    node* p=creNode(x);
    if(head==NULL)
    {
        head=p;
        tail=p;
        return;
    }
    p->next=head;
    head->prev=p;
    head=p;
}
void InsTail(int x)
{
    node* p=creNode(x);
    if(head==NULL)
    {
        head=p;
        tail=p;
        return;
    }
    tail->next=p;
    p->prev=tail;
    tail=p;
}
void DelHead()
{
    if(head==NULL)
        return;
    head=head->next;
    head->prev=NULL;
}
void DelTail()
{
    if(head==NULL)
        return;
    tail=tail->prev;
    tail->next=NULL;
}
// duyệt dslk
// duyệt từ đầu tới cuối
void print()
{
    node* p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
// duyệt từ cuối về đầu
void revprint()
{
    node* p=tail;
    if(p==NULL)
        return;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }
    cout<<endl;
}
int main()
{
    head=NULL;
    InsTail(2);
    print(); revprint();
    InsTail(4);
    print(); revprint();
    InsHead(6);
    print(); revprint();
    InsTail(8);
    print(); revprint();
    DelHead();
    print(); revprint();
    DelTail();
    print(); revprint();
}
