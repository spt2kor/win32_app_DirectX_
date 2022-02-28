#include <iostream>
#include "RealNumber.h"
#include "ComplexNumber.h"

using namespace std;

RealNumber::RealNumber (double r)
  : Number (BaseConstructor()),
    val (r)
{
  cout << "Constructing a RealNumber\n";
}
 
RealNumber::RealNumber (const RealNumber &r)
  : Number (BaseConstructor()),
    val (r.val)
{
  cout << "Constructing a RealNumber using RealNumber::RealNumber\n";
}
 
RealNumber::~RealNumber()
{
  cout << "Inside RealNumber::~RealNumber()\n";
}
 
Number RealNumber::operator + (const Number &n) const
{ 
	cout << "Inside RealNumber::operator +()\n";
  return n.realAdd (*this); 
}
 
Number RealNumber::realAdd (const Number &n) const
{
  cout << "RealNumber::realAdd\n";
  const RealNumber *rn = dynamic_cast <const RealNumber  *> (&n);
  return Number::makeReal (this->val + rn->val);
}
 
Number RealNumber::complexAdd (const Number &n) const
{
  cout << "RealNumber::complexAdd\n";
  const Complex *cn = dynamic_cast <const Complex *> (&n);
  return Number::makeComplex (this->val + cn->rpart, cn->ipart);
}