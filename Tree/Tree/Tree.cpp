#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
	int info;
	Node *left, *right;
	Node *parent;
	Node(int info = 0, Node *left = NULL, Node *right = NULL)
	{
		this->info = info;
		this->left = left;
		this->right = right;
	}

	void Print()
	{
		cout << info << " ";
	}
};

struct Tree
{
	Node *root;
	Tree()
	{
		root = NULL;
	}
	
	void AddR(int x)
	{
		AddR(root, x);
	}
	void AddR(Node *&r, int x)
	{
		if (r == NULL)
			r = new Node(x, r);
		if (r->info == x)
			return;
		if (x < r->info)
		{
			AddR(r->left, x);
			r->left->parent = r;
		}
		else
		{
			AddR(r->right, x);
			r->right->parent = r;
		}
	}

	void Print()
	{
		queue <Node *> que;
		if (root == NULL)
			return;
		que.push(root);
		while (!que.empty())
		{
			Node *n = que.front();
			que.pop();
			if (n->left != NULL)
				que.push(n->left);
			if (n->right != NULL)
				que.push(n->right);
			n->Print();
		}
	}
	Node * Find(int x)
	{
		return Find(root, x);
	}
	Node * Find(Node *r, int x)
	{
		if (r == NULL)
			return r;
		if (r->info == x)
			return r;
		if (x < r->info)
			return Find(r->left, x);
		if (x > r->info)
			return Find(r->right, x);
	}
	
	void Depth()
	{
		cout << Depth(root);
	}

	int Depth(Node *r)
	{
		if (r == NULL) 
			return -1;
		else
		{
			return (max(Depth(r->left), Depth(r->right)) + 1);
		}
	}
	
	bool Symmetric()
	{
		return Symmetric(root);
	}

	bool Symmetric(Node *p)
	{
		if (p == NULL) 
			return true;
		if (p->left == NULL && p->right == NULL)
			return true;
		else if (p->left != NULL && p->right != NULL)
		{
			if (Symmetric(p->left) && Symmetric(p->right))
				return true;
			else 
				return false;
		}
		else
			return false;
	}
	
	
		
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	Tree t;
	t.AddR(5);
	t.AddR(6);
	t.AddR(8);
	t.AddR(2);
	t.Print();
	cout << endl;
	system("pause");
	return 0;
}