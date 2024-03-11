#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

#include <sstream>

using namespace std;
class Rational
{

public:
	long long a, b; //a-????????? b-???????????//
	Rational(long long chislit = 0, long long znamenat = 1) :a(chislit), b(znamenat)
	{
		a = chislit;
		if (znamenat != 0)
			b = znamenat;
		else
		{
			cout << "Ne mogu podelit na ZERO\n";
			exit(1);
		}
	}
	Rational Add(Rational);
	Rational Sub(Rational);
	Rational Mult(Rational);
	Rational Div(Rational);
	Rational operator+ (Rational);
	Rational operator- (Rational);
	Rational operator* (Rational);
	Rational operator* (int);
	Rational operator/ (Rational);
	Rational operator= (Rational);
	void Print();
	void Change(int, int);
	long long Nod(long long, long long);
};
