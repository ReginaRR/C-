#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int info;
	Node *left, *right;
	Node(int info = 0, Node *left = NULL, Node *right = NULL)
	{
		this->info = info; 
		this->left = left; 
		this->right = right;
	}
};

struct Tree
{
	Node *root;
	Tree()
	{
		root = NULL;
	}
	void Print()
	{
		Print(root);
	}
	void Print(Node *r)
	{
		if (r != NULL)
		{
			Print(r->left);
			cout << r->info;
			Print(r->right);
		}
	}
	void AddR(int x)
	{
		AddR(root, x);
	}
	void AddR(Node *&r, int x)
	{
		if (r == NULL)
		{
			r = new Node(x, r);
			r->left = r->right = NULL;
		}
		if (r->info == x)
			return;
		if (x < r->info)
			AddR(r->left, x);
		else
			AddR(r->right, x);
	}

	void deleteTree()
	{
		deleteTree(root);
	}


	void deleteTree(Node *r)
	{
		if (r != NULL) 
		{
			deleteTree(r->left); 
			deleteTree(r->right); 
			delete r; 
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
	void PrintL()
	{
		queue <Node *> q;
		if (root == NULL) return;
		q.push(root);
		while (!q.empty())
		{
			Node *r = q.front();
			q.pop();
			if (r->left != NULL) q.push(r->left);
			if (r->right != NULL) q.push(r->right);
			cout << r->info;
		}
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
	bool EqualStruct(Tree t)
	{
		return EqualStruct(root, t.root);
	}
	bool EqualStruct(Node *p, Node *pp)
	{
		if (p == NULL && pp == NULL)
			return true;
		else if ((p != NULL && pp != NULL))
		{
			if (EqualStruct(p->left, pp->left) && EqualStruct(p->right, pp->right)) 
				return true;
			else 
				return false;
		}
		else
			return false;
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
	Tree tree1, tree2;
	tree1.AddR(5);
	tree1.AddR(7);
	tree1.AddR(3);
	tree1.AddR(0);
	tree2.AddR(5);
	tree2.AddR(7);
	tree2.AddR(2);
	tree2.AddR(1);
	tree1.PrintL();
	cout << endl;
	tree2.PrintL();
	cout << endl;
	cout << "Depth = ";
	tree1.Depth();
	cout << endl;
	if (tree1.EqualStruct(tree2))
		cout << "equal"; 
	else 
		cout << "not equal";
	cout << endl;
	if (tree2.Symmetric()) 
		cout << "symmetric"; 
	else 
		cout << "not symmetric";
	cout << endl;

	tree1.deleteTree();
	tree1.PrintL();


	system("pause");
	return 0;
}