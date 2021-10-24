#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node* CreNode(int x)
{
    node *p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void CreTree(node *root)
{
    root=NULL;
}
// thêm một node vào BST
void InsNode(node* &root, node* p)
{
    if(root)
    {
        if(root->data==p->data)
            return;
        if(root->data>p->data)
            InsNode(root->left,p)
        else
            InsNode(root->right,p)
    }
    else root=p;
}
// tìm node trong BST
node* FindNode(node *root, int x)
{
    if(root)
    {
        if(root->data==x) return root;
        if(root->data>x)
            return FindNode(root->left, x);
        else return FindNode(root->right, x);
    }
    return NULL;
}
// hủy một nút trong BST
// hàm tìm node bé nhất của cây con phải
void FindRnReplace(node *p, node* &RTree)
{
    if(RTree->left)
        FindRnReplace(p,RTree->left)
    else
    {
        p->data=RTree->data;
        p=RTree;
        RTree=RTree->right;
    }
}
// hàm tìm node lớn nhất của cây con trái
void FindLnReplace(node *p, node* &LTree)
{
    if(LTree->right)
        FindLnReplace(p, LTree->right)
    else
    {
        p->data=LTree->data;
        p=LTree;
        LTree=LTree->left;
    }
}
// hàm xóa node
void DelNode(node* &root, int x)
{
    if(root)
    {
        if(root->data>x)
            DelNode(root->left,x);
        else if(root->data<x)
            DelNode(root->right,x);
        else
        {
            node *p=root;
            if(root->left==NULL)
                root=root->right;
            else if(root->right==NULL)
                root=root->left;
            else
                FindRnReplace(p, root->right);
            delete p;
        }
    }
// biểu diễn bằng mảng
struct tree
{
    int data[1000];
    int Nodes;
};
// Kiểm tra cây rỗng
bool kt(tree T)
{
    return T.Nodes==0;
}
// Xác định node trái
int Lefttree (int i, tree T)
{
    return 2*i;
}
// Xác định node phải
int Righttree(int i, tree T)
{
    return 2*i+1;
}
// Duyệt theo thứ tự trước
void NodeLeftRight(int i, tree T)
{
    if (T.data[i]!=-1)
    {
        cout << T.data[i] <<" ";
        NodeLeftRight(Lefttree(i,T),T);
        NodeLeftRight(Righttree(i,T),T);
    }
}
// Duyệt theo thứ tự giữa
void LeftNodeRight(int i, tree T)
{
    if (T.data[i]!=-1)
    {
        LeftNodeRight(Lefttree(i,T),T);
        cout << T.data[i] <<" ";
        LeftNodeRight(Righttree(i,T),T);
    }
}
// Duyệt theo thứ tự sau
void LeftRightNode(int i, tree T)
{
    if (T.data[i]!=-1)
    {
        LeftRightNode(Lefttree(i,T),T);
        LeftRightNode(Righttree(i,T),T);
        cout << T.data[i] <<" ";
    }
}
int main()
{

}

