#ifndef COMPLEX
#define COMPLEX

#include <math.h>

class Complex {
public:
	Complex();
	Complex(double);
	Complex(double, double);
	double fun1();
	double fun2();
	double fun3();
	double fun4();
	typedef double(Complex::*ComplexMethod)(void);
	ComplexMethod methods_arr[4];
private:
	double im;
	double re;
};

#endif
