#include "rational.h"


Rational Rational::Add(Rational s)
{
	Rational Sum;
	Sum.a = a * s.b + b * s.a;
	Sum.b = b * s.b;
	int c = Nod(Sum.b, Sum.a);
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}



Rational Rational::Sub(Rational s)
{
	Rational Sum;
	Sum.a = a * s.b - b * s.a;
	Sum.b = b * s.b;
	int c = Nod(Sum.b, Sum.a);
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}



Rational Rational::Mult(Rational s)
{
	Rational Sum;
	Sum.a = a * s.a;
	Sum.b = b * s.b;
	int c = Nod(Sum.b, Sum.a);
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}




Rational Rational::Div(Rational s)
{

	Rational Sum;
	Sum.a = a * s.b;
	Sum.b = b * s.a;
	if (s.a == 0)
	{
		cout << "nelzia delit na Zero" << endl;
		exit(1);
	}

	int c = Nod(Sum.b, Sum.a);
	Sum.a = Sum.a / c;
	Sum.b = Sum.b / c;
	return Sum;
}

void Rational::Print()
{
	cout << a << "/" << b << endl;
}

void Rational::Change(int d, int e)
{

	a = d;
	if (e)
		b = e;
	else
	{
		cout << "ne mogu delit na zero" << endl;
		exit(1);
	};

	int c = Nod(b, a);
	a = a / c;
	b = b / c;
}

Rational Rational::operator- (Rational s)
{
	Rational r;
	r.a = a * s.b - b * s.a;
	r.b = b * s.b;
	long long c = Nod(r.b, r.a);
	r.a = r.a / c;
	r.b = r.b / c;
	return r;
}

Rational Rational::operator+ (Rational s)
{
	Rational r;
	r.a = a * s.b + b * s.a;
	r.b = b * s.b;
	int c = Nod(r.b, r.a);
	r.a = r.a / c;
	r.b = r.b / c;
	return r;
}

Rational Rational::operator/ (Rational s)
{
	Rational r;
	r.a = a * s.b;
	r.b = b * s.a;
	if (r.b == 0)
	{
		cout << "nelzia delit na Zero" << endl;
		exit(1);
	}
	long long c = Nod(r.b, r.a);
	r.a = r.a / c;
	r.b = r.b / c;
	return r;
}
Rational Rational::operator* (int s)
{
	Rational r;
	r.a = a * s;
	r.b = b;
	long long c = Nod(r.b, r.a);
	r.a = r.a / c;
	r.b = r.b / c;
	return r;
}

Rational Rational::operator* (Rational s)
{
	Rational r;
	r.a = a * s.a;
	r.b = b * s.b;
	long long c = Nod(r.b, r.a);
	r.a = r.a / c;
	r.b = r.b / c;
	return r;
}


Rational Rational::operator= (Rational s)
{
	a = s.a;
	if (s.b)
		b = s.b;
	else
	{
		cout << "ne mogu delit na zero" << endl;
		exit(1);
	};
	return *this;
}



long long Rational::Nod(long long a, long long b)
{
	if (a == 0 && b == 0)
		throw "Daun tupoi";
	if (b == 0)
		return a;
	if (a == 0)
		return b;
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return Nod(abs(a % b), abs(b));
	else
		return Nod(abs(a), abs(b % a));
}