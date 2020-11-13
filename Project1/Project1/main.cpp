#include <iostream>
#include "function.h"
#include "Term.h"
#include "mono.h"
using mth :: mono;
using mth :: function;
int main() 
{   
	mono fx =  mono(3, 2);
	
	mono gx = mono(1, 1);
	function f;
	f += gx;
	f += fx;
	f.print();
	std::cout << f(5);

	return 0;
}