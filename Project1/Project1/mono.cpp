#include "mono.h"
#include "Term.h"
#include <cmath>
#include <cstdio>


mth::mono::mono(double c, double n) : Term(c)
{
    pow = n;
}

double mth::mono::operator() (double x)
{
    return coeff*(std::pow(x, pow));
}

void mth::mono::print(void)
{
    mth::Term::print();
    printf("x^%.3f", pow);
}