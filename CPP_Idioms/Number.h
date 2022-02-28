#ifndef __Number_
#define __Number_

#include "BaseConstructor.h"

class RealNumber;
class Complex;
class Number;
 
class Number
{
    friend class RealNumber;
    friend class Complex;
 
  public:
    Number ();
    Number & operator = (const Number &n);
    Number (const Number &n);
    virtual ~Number();
 
    virtual Number operator + (Number const &n) const;
    void swap (Number &n) throw ();
 
    static Number makeReal (double r);
    static Number makeComplex (double rpart, double ipart);
 
  protected:
    Number (BaseConstructor);
 
  private:
    void redefine (Number *n);
    virtual Number complexAdd (const Number &n) const;
    virtual Number realAdd (const Number &n) const;
 
    Number *rep;
    short referenceCount;
};

#endif