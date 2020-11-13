#ifndef TERM
#define TERM
#include <iostream>
namespace mth 
{

	class Term
	{
	    public:
			Term(double c =0) { coeff = c; }
			virtual ~Term() {std::cout << "Term destructor.\n";}
			virtual double operator() (double x) { return 0; };
			virtual void print(void);
			
	    protected:
		    double coeff;
	};

}

#endif