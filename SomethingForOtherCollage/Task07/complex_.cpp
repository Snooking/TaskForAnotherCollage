#include "complex_.h"

Complex::Complex()
{
	methods_arr[0] = &Complex::fun1;
	methods_arr[1] = &Complex::fun2;
	methods_arr[2] = &Complex::fun3;
	methods_arr[3] = &Complex::fun4;
	re = 1;
	im = 0;
}

Complex::Complex(double value)
{
	methods_arr[0] = &Complex::fun1;
	methods_arr[1] = &Complex::fun2;
	methods_arr[2] = &Complex::fun3;
	methods_arr[3] = &Complex::fun4;
	re = value;
	im = value;
}

Complex::Complex(double re, double im)
{
	methods_arr[0] = &Complex::fun1;
	methods_arr[1] = &Complex::fun2;
	methods_arr[2] = &Complex::fun3;
	methods_arr[3] = &Complex::fun4;
	this->re = re;
	this->im = im;
}

double Complex::fun1()
{
	return re;
}

double Complex::fun2()
{
	return im;
}

double Complex::fun3()
{
	return ((re*re) + (im*im));
}

double Complex::fun4()
{
	return sqrt(fun3());
}