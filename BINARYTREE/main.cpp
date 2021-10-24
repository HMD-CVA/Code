#include <bits/stdc++.h>
using namespace std;
int main()
{
    struct node
    {
        int data;
        node *left;
        node *right;
    };
    node *creatNode(int x)
    {
        node *p=new node;
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    void creatTree(node* &root)
    {
        root=NULL;
    }
    //duyet cay nhi phan
    //duyet theo thu tu truoc
    void NLR(node *root)
    {
        if(root)
        {
            //xuli root
            NLR(root->left);
            NLR(root->right);
        }
    }
    //duyet theo thu tu giua
    void LNR(node *root)
    {
        if(root)
        {
            LNR(root->left);
            //xuli root
            LNR(root->right);
        }
    }
    //duyet theo thu tu sau
    void LRN(node *root)
    {
        if(root)
        {
            LRN(root->left);
            LRN(root->right);
            //xuli root
        }
    }
    //huy cay
    void desTree(node* &root)
    {
        if(root)
        {
            desTree(root->left);
            desTree(root->right);
            delete root;
        }
    }
}
