#include "stdafx.h"
#include <iostream>

using namespace std;

struct E
{
	int info;
	E* next;
	E(int info = 0, E* next = NULL)
	{
		this->info = info;
		this->next = next;
	}
};

struct List
{
	E *first;
	E *last;
	List()
	{
		first = last = NULL;
	}

	void AddListLast(List l) 
	{
		for (E *p = l.first; p != NULL; p = p->next)
		{
			AddLast(p->info);
		}
	}
	void AddLast(int x)
	{
		for (E *p = first; p != NULL; p = p->next)
			last = p;
		last->next = new E(x);
	}

	void Print()
	{
		for (E *p = first; p != NULL; p = p->next)
			cout << p->info << " ";
		cout << endl;
	}

	void AddBegin(int x)
	{
		first = new E(x, first);
	}


	void Insert(int value)
	{
		E *prev = NULL;
		E *succ = first;
		while (succ != NULL && succ->info < value)
		{
			prev = succ;
			succ = succ->next;
		}

		E *newE = new E(value, succ);
		if (succ == NULL) 
			last = newE;
		if (prev == NULL)
			first = newE;
		else
			prev->next = newE;
	}

	void DeleteNumber(int value)
	{
		E* prev = NULL;
		E *current = first;
		while (current->info != NULL)
		{
			if (current->info == value)
			{
				if (prev != NULL)
				{
					prev->next = current->next;
				}
				if (current == last)
				{
					last = prev;
				}
				delete current;
				break;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		
	}

	bool operator == (List list)
	{
		E *p, *pp;
		for (p = list.first, pp = first; p != NULL && pp != NULL; p = p->next, pp = pp->next)
		{
			if (p->info != pp->info) 
				return false;
		}
		if (p == NULL && pp == NULL)
			return true;
		else
			return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	List list1;
	List list2;
	list1.AddBegin(4);
	list1.AddBegin(3);
	list1.AddBegin(2);
	list1.AddBegin(1);
	list1.Print();
	list2.AddBegin(4);
	list2.AddBegin(3);
	list2.AddBegin(2);
	list2.AddBegin(1);
	list2.Print();
	if (list1.operator==(list2))
		cout << "true" << endl;
	else 
		cout << "false" << endl;
	list2.AddLast(6);
	list2.AddLast(8);
	list1.Print();
	list2.Print();
	if (list1.operator==(list2)) 
		cout << "true" << endl;
	else 
		cout << "false" << endl;
    list2.DeleteNumber(6);
	list2.Insert(9);
	list1.Print();
	list2.Print();
	list1.AddListLast(list2);
	list1.Print();

	system("pause");
	return 0;
}