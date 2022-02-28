#ifndef __RealNumber_
#define __RealNumber_

#include "Number.h"

class RealNumber : public Number
{
  friend class Complex;
  friend class Number;
 
  RealNumber (double r);
  RealNumber (const RealNumber &r);
  virtual ~RealNumber ();
 
  virtual Number operator + (const Number &n) const;
  virtual Number realAdd (const Number &n) const;
  virtual Number complexAdd (const Number &n) const;
 
  double val;
};


#endif