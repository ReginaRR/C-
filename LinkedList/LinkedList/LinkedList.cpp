#include "stdafx.h"
#include <iostream>

using namespace std;

struct E
{
	int coef;
	int power;
	E *next;
	E(int coef = 0, int power = 0, E *link = NULL)
	{
		this->coef = coef;
		this->power = power;
		this->next = link;
	}

	void Print()
	{
		if (power != 0)
		{
			cout << coef << "x^" << power;
		}
		else
			cout << coef;
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


	

	void Print()
	{
		for (E *p = first; p != NULL; p = p->next)
		{
			p->Print();
			if(p->next != 0)
				cout << " + ";
		}
		cout << endl;
	}

	void AddBegin(int ccoef, int ppower)
	{
		if (ccoef != 0)
		{
			if (first == NULL)
			{
				first = new E(ccoef, ppower);
				last = first;
			}
			else
			{
				first = new E(ccoef, ppower, first);
			}
		}
	}

	void AddEnd(int ccoef, int ppower)
	{
		if (last == NULL)
		{
			first = new E(ccoef, ppower);
			last = first;
		}
		else
		{
			E* temp = last;
			last = new E(ccoef, ppower);
			temp->next = last;
		}
	}

	int Value(int x)
	{
		int sum = 0;
		for (E *p = first; p != NULL; p = p->next)
		{
			int value = 1;
			for (int i = 1; i <= p->power; i++)
			{
				value *= x;
			}

			sum += (p->coef) * value;
		}

		return sum;
	}

	List SumOfPolynom(List l2)
	{
		List l3;
		for (E *p = first; p != NULL; p = p->next)
		{
			for (E *pp = l2.first; pp != NULL; pp = pp->next)
			{
				if (p->power < pp->power)
				{
					l3.AddEnd(pp->coef, pp->power);
				}

				if (p->power > pp->power)
				{
					l3.AddEnd(p->coef, p->power);
					l2.first = l2.first->next;
					break;
				}

				if (p->power == pp->power)
				{
					l3.AddEnd((p->coef + pp->coef), p->power);
					l2.first = l2.first->next;
					break;
				}
			}
		}
		return l3;
	}

	List CompositionOfPolynoms(List l2)
	{
		List l3;
		for (E *p = first; p != NULL; p = p->next)
		{
			for (E *pp = l2.first; pp != NULL; pp = pp->next)
			{
				l3.AddEnd(p->coef * pp->coef, p->power + pp->power);
			}
		}

		return l3;
	}

};


int main()
{
	List l1;
	//l1.AddBegin(3, 0);
	l1.AddBegin(4, 1);
	l1.AddBegin(2, 3);
	l1.AddBegin(0, 4);
	l1.AddEnd(3, 0);
	l1.Print();

	List l2;
	//l2.AddBegin(4, 0);
	l2.AddBegin(6, 1);
	l2.AddBegin(3, 2);
	l2.AddEnd(4, 0);
	l2.Print();
	cout << l2.Value(2);

	List l3 = l2.SumOfPolynom(l1);
	cout << endl;
	l3.Print();

	List l4 = l2.CompositionOfPolynoms(l1);
	cout << endl;
	l4.Print();
	system("pause");
    return 0;
}

