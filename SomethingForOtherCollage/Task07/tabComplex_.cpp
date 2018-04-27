#include "tabComplex_.h"

TabComplex::TabComplex()
{
	for (int i = 0; i < 10; i++) {
		Complex temp(i);
		tabC[i] = temp;
	}
}


std::ostream & operator<<(std::ostream & os, TabComplex & tabComp)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			os << CALL_MEMBER_FN(tabComp.tabC[i], (tabComp.tabC[i].methods_arr[j]))() << std::endl;
		}
	}
	return os;
}