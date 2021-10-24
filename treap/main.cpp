#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    int pro;
    node *left;
    node *right;
};
node* createnode(int x, int y)
{
    node *p = new node;
    p->data = x;
    p->pro = y;
    p->left = NULL;
    p->right = NULL;
    return p;
}
//thao tac xoay cay
// xoay phai
node* xoayphai(node* &y)
{
    node *x = y->left;
    node *p = x->right;
    x->right = y;
    y->left = p;
    return x;
}
// xoay trai
node* xoaytrai(node *y)
{
    node *x = y->right;
    node *p = x->left;
    x->left = y;
    y->right = p;
    return x;
}
void createtree(node *root)
{
    root=NULL;
}
// them node
void addnode(node* &root, node* p)
{
    if(root)
    {
        if(root->data > p->data)
        {
            addnode(root->left, p);
            if(root->pro > root->left->pro)
                xoayphai(root);
        }
        else if(root->data < p->data)
        {
            addnode(root->right, p);
            if(root->pro > root->right->pro)
                xoaytrai(root);
        }
        else
        {
            root->data = p->data;
            if(p->pro < root->pro)
                root->pro = p->pro;
        }
    }
    else root = p;
}
void deletenode(node* &root, int x)
{
    if(root)
    {
        if(root->data < x)
            deletenode(root->right, x);
        else if(root->data > x)
            deletenode(root->left, x);
        else
        {
            //node co 2 node con
            while((root->left != NULL) && (root->right != NULL))
            {
                if(root->left->pro < root->right->pro)
                    root = xoayphai(root);
                else
                {
                    if(root->left->pro > root->right->pro)
                        root = xoaytrai(root);
                }
            }
            node *p = root;
            if(root->left == NULL)
                root = root->right;
            else
            {
                if(root->right == NULL)
                    root = root->left;
            }
            delete p;
        }
    }
}
void NLR(node* root)
{
    if (root)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(node* root)
{
    if (root)
    {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
void LRN(node* root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}
int main()
{
	int n,a,b;
	node *root;
	node *p;
	createtree(root);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a>>b;
		p = createnode(a,b);
		addnode(root, p);
	}
	LNR(root);
}
