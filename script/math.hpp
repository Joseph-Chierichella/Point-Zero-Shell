#include <iostream>
#include "indenting.hpp"
#ifndef MATH_HPP
#define MATH_HPP

void add(float add1, float add2) 
{
	using namespace std;
	float add3 = add1 + add2;
	cout << findent << ": " << add1 << " + " << add2 << " = " << add3 << endl;
}
void sub(float sub1, float sub2) 
{
	using namespace std;
	float sub3 = sub1 - sub2;
	cout << findent << ": " << sub1 << " - " << sub2 << " = " << sub3 << endl;
}
void tim(float tim1, float tim2) 
{
	using namespace std;
	float tim3 = tim1 * tim2;
	cout << findent << ": " << tim1 << " * " << tim2 << " = " << tim3 << endl;
}
void div(float div1, float div2) 
{
	using namespace std;
	float div3 = div1 / div2;
	cout << findent << ": " << div1 << " / " << div2 << " = " << div3 << endl;
}
int addition()
{	
	using namespace std;
	float add11;
	cout << findent << ": ";
	cin >> add11;
	float add12;
	cout << findent << ": " << add11 << " + ";
	cin >> add12;
	add(add11, add12);
	return 0;
}
int subtraction()
{	
	using namespace std;
	float sub11;
	cout << findent << ": ";
	cin >> sub11;
	float sub12;
	cout << findent << ": " << sub11 << " - ";
	cin >> sub12;
	sub(sub11, sub12);
	return 0;
}
int multiplication()
{	
	using namespace std;
	float tim11;
	cout << findent << ": ";
	cin >> tim11;
	float tim12;
	cout << findent << ": " << tim11 << " * ";
	cin >> tim12;
	tim(tim11, tim12);
	return 0;
}
int division()
{	
	using namespace std;
	float div11;
	cout << findent << ": ";
	cin >> div11;
	float div12;
	cout << findent << ": " << div11 << " / ";
	cin >> div12;
	div(div11, div12);
	return 0;
}

#endif