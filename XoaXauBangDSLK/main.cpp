#include <bits/stdc++.h>
using namespace std;
struct Node
{
	string data;
	Node* next;
};
Node* CreateNode(string init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}
struct LinkedList
{
	Node* head;
	Node* tail;
};
void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}
void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}
int RemoveHead(LinkedList& l, string& x)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;
		l.head = node->next;
		delete node;
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}
void PrintList(LinkedList l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->next;
		}
	}
}
int main()
{
    freopen("in.inp","r",stdin);
    LinkedList list;
	CreateList(list);
    int n,k,dem=0;
    cin >> n;
    k=n;
    string s;
    while(n--)
    {
        cin >> s;
        Node*p=CreateNode(s);
        AddHead(list,p);
    }
    PrintList(list);
}
