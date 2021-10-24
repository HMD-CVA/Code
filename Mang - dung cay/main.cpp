#include<bits/stdc++.h>

using namespace std;

struct tree
{
    int data[1000];
    int nodes;
};
bool kt(tree T)
{
    return T.nodes==0;
}
int lefttree (int i, tree T)
{
    return 2*i;
}
int righttree(int i, tree T)
{
    return 2*i+1;
}
void NLR(int i, tree T)
{
    if (T.data[i]!=-1)
    {
        cout << T.data[i] <<" ";
        NLR(lefttree(i,T),T);
        NLR(righttree(i,T),T);
    }
}
void LNR(int i, tree T)
{
    if (T.data[i]!=-1)
    {
        LNR(Lefttree(i,T),T);
        cout << T.data[i] <<" ";
        LNR(righttree(i,T),T);
    }
}
void LRN(int i, tree T)
{
    if (T.data[i]!=-1)
    {
        LRN(lefttree(i,T),T);
        LRN(righttree(i,T),T);
        cout << T.data[i] <<" ";
    }
}
int main()
{

}
