#include "stdafx.h"
#include<iostream>
using namespace std;
class RationalNumber
{
    public:
	    int numerator;
	    int denominator;

    public:
	    RationalNumber(int numerator = 0, int denominator = 1)
	    {
		    this->numerator = numerator;
		    if (denominator != 0)
			    this->denominator = denominator;
		    else
				this->denominator = 1;
		}

		RationalNumber Sum (RationalNumber r2)
		{
			RationalNumber r;
			r.denominator = denominator * r2.denominator;
			r.numerator = numerator * r2.denominator + r2.numerator * denominator;
			//Print(r);
			return r;
		}

		RationalNumber Subtraction(RationalNumber r2)
		{
			RationalNumber r;
			r.denominator = denominator * r2.denominator;
			r.numerator = numerator * r2.denominator - r2.numerator * denominator;
			return r;
		}

		

		RationalNumber Multiplication(RationalNumber r2)
		{
			RationalNumber r;
			r.numerator = numerator * r2.numerator;
			r.denominator = denominator * r2.denominator;
			return r;
		}

		RationalNumber Division(RationalNumber r2)
		{
			RationalNumber r;
			r.denominator = denominator * r2.numerator;
			r.numerator = numerator * r2.denominator;
			return r;
		}


		void NormalForm()
		{
			if (numerator > denominator)
				cout << "The integer part of the number " << (int)(numerator / denominator) << endl;
		}

		void Improve()
		{
			if (numerator < denominator)
			{
				for (int i = abs(numerator); i > 1; i--)
				{
					if ((numerator % i == 0) && (denominator % i == 0))
					{
						numerator /= i;
						denominator /= i;
						break;
					}
				}
			}
			else
			{
				for (int i = abs(denominator); i >= 1; i--)
				{
					if ((numerator % i == 0) && (denominator % i == 0))
					{
						numerator /= i;
						denominator /= i;
						break;
					}
				}
			}
		}

		void Print()
		{
			cout << numerator << "/" << denominator << endl;
		}
};

int main()
{
	RationalNumber r1(6, 5); 
	RationalNumber r2(5, 5);
	RationalNumber r3 = r1.Sum(r2);
	r3.Print();
	r3.Improve();
	r3.Print();
	r3.NormalForm();
	RationalNumber r4 = r1.Division(r2);
	r4.Print();
	r4.Improve();
	r4.Print();
	RationalNumber r5 = r1.Multiplication(r3);
	r5.Print();
	r5.Improve();
	r5.Print();
	RationalNumber r6 = r1.Subtraction(r3);
	r6.Print();
	r6.Improve();
	r6.Print();
	
	system("pause");
	return 0;
}

