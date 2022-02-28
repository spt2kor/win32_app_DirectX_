#include <iostream>
#include "ComplexNumber.h"
#include "RealNumber.h"

using namespace std;

Complex::Complex (double d, double e)
  : Number (BaseConstructor()),
    rpart (d),
    ipart (e)
{
  cout << "Constructing a Complex\n";
}
 
Complex::Complex (const Complex &c)
  : Number (BaseConstructor()),
    rpart (c.rpart),
    ipart (c.ipart)
{
  cout << "Constructing a Complex using Complex::Complex\n";
}
 
Complex::~Complex()
{
  cout << "Inside Complex::~Complex()\n";
}
 
Number Complex::operator + (const Number &n) const
{ 
	cout << "Inside Complex::operator +()\n";
	return n.complexAdd (*this); 
}
 
Number Complex::realAdd (const Number &n) const
{
  cout << "Complex::realAdd\n";
  const RealNumber &rn = dynamic_cast <const RealNumber &> (n);
  return Number::makeComplex (this->rpart + rn.val, 
                              this->ipart);
}
 
Number Complex::complexAdd (const Number &n) const
{
  cout << "Complex::complexAdd\n";
  const Complex *cn = dynamic_cast <const Complex *> (&n);
  return Number::makeComplex (this->rpart + cn->rpart, 
                              this->ipart + cn->ipart);
}