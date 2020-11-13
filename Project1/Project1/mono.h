#ifndef MONO
#define MONO
#include "Term.h"
#include <iostream>

namespace mth 
{
	class mono : public Term
	{
	     public:
			 mono(double c =0, double n=0);
			 mono(const mono& m)
			 {
				 std::cout << "Monomial copy.\n";
				 coeff = m.coeff;
				 pow = m.pow;
			 };
			 double degree(void) { return pow; }
			 double operator() (double x);
			 void print(void);
	     private:
			 double pow;
	};

}
#endif

