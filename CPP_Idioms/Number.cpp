#include <iostream>
#include "Number.h"
#include "RealNumber.h"
#include "ComplexNumber.h"

using namespace std;



/// Used only by the letters.
Number::Number (BaseConstructor)
: rep (0),
  referenceCount (1)
{
	cout<<"\n Number::Number (BaseConstructor)"<<endl;
}
 
/// Used by user and static factory functions.
Number::Number () 
  : rep (0),
    referenceCount (0)
{
	cout<<"\n Number::Number ()"<<endl;
}
 
/// Used by user and static factory functions.
Number::Number (const Number &n)
: rep (n.rep),
  referenceCount (0)
{
  cout << "Constructing a Number using Number::Number\n";
  if (n.rep)
    n.rep->referenceCount++;
}
 
Number Number::makeReal (double r)
{
	cout << "Number::makeReal\n";
  Number n;
  n.redefine (new RealNumber (r));
  return n;
}
 
Number Number::makeComplex (double rpart, double ipart)
{
	cout << "Number::makeComplex\n";
  Number n;
  n.redefine (new Complex (rpart, ipart));
  return n;
}
 
Number::~Number()
{
	if(rep)
	{
		cout << "\n Number::~Number() count:"<<(rep->referenceCount -1)<<endl;
		if (--rep->referenceCount == 0)
		{
			cout << "Now deleting Number::~Number()\n";
			delete rep;
		}
	}
}
 
Number & Number::operator = (const Number &n)
{
  cout << "Assigning a Number using Number::operator=\n";
  Number temp (n);
  this->swap (temp);
  return *this;
}
 
void Number::swap (Number &n) throw ()
{
	cout << "Inside Number::swap()\n";
  std::swap (this->rep, n.rep);
}
 
Number Number::operator + (const Number &n) const
{
	cout << "Inside Number::operator +()\n";
  return rep->operator + (n);
}
 
Number Number::complexAdd (const Number &n) const 
{
	cout << "Inside Number::complexAdd()\n";
  return rep->complexAdd (n);
}
 
Number Number::realAdd (const Number &n) const
{
	cout << "Inside Number::realAdd()\n";
  return rep->realAdd (n);
}
 
void Number::redefine (Number *n)
{
	cout << "Inside Number::redefine()\n";
  if (rep && --rep->referenceCount == 0)
    delete rep;
  rep = n;
}