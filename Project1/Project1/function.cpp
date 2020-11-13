#include "function.h"
#include "Term.h"
#include <vector>
#include <cstdio>
#include <memory>
#define spt shared_ptr
using std::spt;
using std::make_shared;


void mth::function::print(void)
{
	for (std::vector<spt<Term>>::iterator i = terms.begin(); i != terms.end(); ++i)
	{
		(*i)->print();
		if (i != terms.end() - 1)
		{
			printf(" + ");
		}
		else
			printf("\n");
	}
}

mth::function::function(Term t)
{
	*this += t;
}

double mth::function::operator() (double x)
{
	double total = 0;
	for (std::vector<spt<Term>>::iterator i = terms.begin(); i != terms.end(); ++i)
		total = total + (*(*i))(x);
	return total;
}


void mth::function::operator+=(Term t)
{
	spt<Term> nw = make_shared<Term>(t);
	terms.push_back(nw);
}

void mth::function::operator+=(mono t)
{
	spt<mono> nw = make_shared<mono>(t);
	terms.push_back(nw);
}


mth::function mth::function::operator=(mth::function f) 
{
	function new_f;
	for (std::vector<spt<Term>>::iterator i = terms.begin(); i != terms.end(); ++i)
	    new_f += (*i);
	return new_f;
}

mth::function mth::function::operator+(mth::function f)
{
	function new_f;
	for (std::vector<spt<Term>>::iterator i = terms.begin(); i != terms.end(); ++i)
		new_f += (*i);
	for (std::vector<spt<Term>>::iterator i = f.begin(); i != f.end(); ++i)
		new_f += (*i);
	return new_f;
}