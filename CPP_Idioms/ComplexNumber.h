#ifndef __ComplexNumber_
#define __ComplexNumber_

#include "Number.h"

class Complex : public Number
{
  friend class RealNumber;
  friend class Number;
 
  Complex (double d, double e);
  Complex (const Complex &c);
  virtual ~Complex ();
 
  virtual Number operator + (const Number &n) const;
  virtual Number realAdd (const Number &n) const;
  virtual Number complexAdd (const Number &n) const;
 
  double rpart, ipart;
};


#endif