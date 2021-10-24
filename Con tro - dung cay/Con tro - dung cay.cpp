#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node* createnode(int x)
{
    node *p = new node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void createtree(node *root)
{
    root=NULL;
}
void addnode(node* &root, node* p)
{
    if(root)
    {
        if(root->data == p->data)
            root->data = p->data;
        if(root->data>p->data)
            addnode(root->left, p)
        else
            addnode(root->right, p)
    }
    else root = p;
}
node* searchnode(node *root, int x)
{
    if(root)
    {
        if(root->data == x) return root;
        else if(root->data > x)
            return searchnode(root->left, x);
        else
            return searchnode(root->right, x);
    }
    return NULL;
}
void timphai(node *p, node* &Tree)
{
    if(Tree->left)
        timphai(p, Tree->left)
    else
    {
        p->data = Tree->data;
        p = Tree;
        Tree = Tree->right;
    }
}
void timtrai(node *p, node* &Tree)
{
    if(Tree->right)
        timtrai(p, Tree->right)
    else
    {
        p->data=Tree->data;
        p=Tree;
        Tree=Tree->left;
    }
}
void deletenode(node* &root, int x)
{
    if(root)
    {
        if(root->data>x)
            deletenode(root->left,x);
        else if(root->data<x)
            deletenode(root->right,x);
        else
        {
            node *p=root;
            if(root->left==NULL)
                root=root->right;
            else if(root->right==NULL)
                root=root->left;
            else
                timphai(p, root->right);
            delete p;
        }
    }
}
int main()
{

}
