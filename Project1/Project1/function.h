#ifndef FUNCTION
#define FUNCTION
#include <vector>
#include <iostream>
#include "mono.h"
#include "Term.h"
#include <memory>
namespace mth
{

	class function
	{
	    public:
			function(Term t);
			function(void) {}
			double operator() (double);
			void operator+=(Term);
			void operator+=(mono);
			void operator+=(std::shared_ptr<Term> t) { terms.push_back(t); }
			function operator+(function);

			function operator=(function);

			void print(void);
			std::vector<std::shared_ptr<Term>>::iterator begin(void)
			{
				return terms.begin();
			}
			std::vector<std::shared_ptr<Term>>::iterator end(void)
			{
				return terms.end();
			}


	    private:
			std::vector<std::shared_ptr<Term>> terms;
	};

}
#endif
