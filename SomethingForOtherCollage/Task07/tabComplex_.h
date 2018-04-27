#ifndef TABCOMPLEX
#define TABCOMPLEX

#include <iostream>
#include "complex_.h"

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class TabComplex {
public:
	TabComplex();
	friend std::ostream& operator<<(std::ostream&, TabComplex&);
private:
	Complex tabC[10];
};

#endif