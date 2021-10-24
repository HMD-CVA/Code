#include <bits/stdc++.h>

using namespace std;


struct node
{
    int data;
    node* next;
};
node* createNode(int x)
{
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}
struct linkedlist
{
    node* head;
    node* tail;
};
void createlinked(linkedlist &l)
{
    l.head = NULL;
    l.tail = NULL;
}
void addhead(linkedlist &l, node* p)
{
    if(l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}
void addtail(linkedlist &l, node* p)
{
    if(l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}
void insertpafterq(linkedlist &l, node* p, node* q)
{
    if(q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if(q == l.tail)
            l.tail = p;
    }
    else
        addhead(l,p);
}
int removehead(linkedlist &l, int x)
{
    node* p;
    if(l.head != NULL)
    {
        p = l.head;
        x = l.head->data;
        l.head = p->next;
        delete p;
        if(l.head == NULL)
            l.tail = NULL;
        return 1;
    }
    return 0;
}
int removepafterq(linkedlist &l, node* q, int x)
{
    node* p;
    if(q != NULL)
    {
        p = q->next;
        if(p != NULL)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
        else
        {
            l.tail = q;
        }
        return 1;
    }
    return 0;
}
void prinf(linkedlist l)
{
    if(l.head != NULL)
    {
        node* p;
        p = l.head;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
}
void prinfvitri(linkedlist l, int a)
{
    node* p;
    int i=0;
    p = l.head;
    while(i != a && p != NULL)
    {
        i++;
        p = p->next;
    }
    if(i == a && p != NULL)
        cout<<p->data;
}
void prinfgiatri(linkedlist l, int x)
{
    node* p;
    p = l.head;
    while(p->data != x && p != NULL)
    {
        p = p->next;
    }
    if(p->data == x && p != NULL)
        cout<<p->data;
}
int main()
{
    int n,a;
    linkedlist l;
    createlinked(l);
    node* p;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        p = createNode(a);
        addtail(l,p);
    }
    prinf(l);
}
