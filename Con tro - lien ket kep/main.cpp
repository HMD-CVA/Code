#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
node* createnode(int a)
{
    node* p = new node;
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct linkedlist
{
    node* head;
    node* tail;
};
void createlist(linkedlist &l)
{
    l.head = NULL;
    l.tail = NULL;
}
void addhead(linkedlist &l, node *p)
{
    if(l.head != NULL)
    {
        p->right = l.head;
        l.head->left = p;
        l.head = p;
    }
    else
    {
        l.head = p;
    }
}
void addtail(linkedlist &l, node *p)
{
    if(l.head != NULL)
    {
        l.tail->right = p;
        p->left = l.tail;
        l.tail = p;
    }
    else
    {
        l.head = p;
        l.tail = p;
    }
}
void insertpafter(linkedlist &l, node *p, node *q)
{
    if(q != NULL)
    {
        node *k = q->right;
        p->right = k;
        p->left = q;
        q->right = p;
        k->left = p;
        if(l.tail == q)
            l.tail = p;
    }
    else
        addhead(l, p);
}
int removehead(linkedlist &l)
{
    if(l.head != NULL)
    {
        node *p = l.head;
        int x = p->data;
        node *q = p->right;
        q->left = NULL;
        l.head = p->right;
        delete p;
        if(l.head == NULL)
            l.tail = NULL;
        return 1;
    }
    return 0;
}
int removepafter(linkedlist &l, node *p, node *q)
{
    int x;
    node *k;
    if(q != NULL)
    {
        x = p->data;
        if(p != NULL)
        {
            k = p->right;
            q->right = k;
            k->left = q;
            delete p;
        }
        else
            l.tail = q;
        return 1;
    }
    return 0;
}
void prinf(linkedlist l)
{
    if(l.head != NULL)
    {
        node *p = l.head;
        while(p != NULL)
        {
           cout<<p->data<<" ";
           p = p->right;
        }
    }
}
void prninfstt(linkedlist l, int x)
{
    node *p = l.head;
    int i=0;
    while(p != NULL && i!=x)
    {
        i++;
        p = p->right;
    }
    if(p != NULL && i==x)
        cout<<p->data;
}
int main()
{
    int n,a;
    linkedlist l;
    createlist(l);
    node *p;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        p = createnode(a);
        addtail(l,p);
    }
    prinf(l);
}
