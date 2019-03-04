#pragma once
#include <math.h>

class fraction
{
public:

	int denominator;
	int numerator;

private:

	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	fraction reciprocal(fraction a)
	{
		int c = a.numerator;

		a.numerator = a.denominator;
		a.denominator = c;

		return a;
	}
public:
	fraction()
	{
		denominator = 1;
		numerator = 0;
	}

	fraction(const fraction &a)
	{
		denominator = a.denominator;
		numerator = a.numerator;
	}

	fraction simplify(fraction a)
	{
		int b;
		if (a.numerator == 0)
			return a;

		if (a.denominator < 0)
		{
			a.numerator = -a.numerator;
			a.denominator = -a.denominator;
		}

		b = gcd(a.numerator, a.denominator);

		a.numerator /= b;
		a.denominator /= b;

		return a;
	}

	fraction reciprocal(fraction a)
	{
		fraction b;

		b.numerator = a.denominator;
		b.denominator = a.numerator;

		return simplify(b);
	}

	//void operator s= 
	/****operators: unary****/

	fraction operator -()
	{
		fraction a;

		a.numerator = -numerator;

		return simplify(a);
	}

	/****operators: arithmetic****/

	fraction operator + (fraction &addend)
	{
		fraction a;

		a.numerator = numerator * addend.denominator + addend.numerator * denominator;
		a.denominator = denominator * addend.denominator;

		return simplify(a);
	}

	fraction operator - (fraction &subtrahend)
	{
		fraction a, c;

		a.denominator = denominator;
		a.numerator = numerator;

		c = -subtrahend;

		return simplify(a + c);
	}

	fraction operator * (fraction &factor)
	{
		fraction a;

		a.denominator = denominator * factor.denominator;
		a.numerator = numerator * factor.numerator;

		return simplify(a);
	}

	fraction operator /(fraction &divisor)
	{
		fraction a;
		fraction c;
		a = reciprocal(divisor);
		c.numerator = numerator;
		c.denominator = denominator;

		return simplify(a * c);
	}
};
