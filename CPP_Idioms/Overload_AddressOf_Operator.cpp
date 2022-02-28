#include <iostream>
using namespace std;




class nonaddressable 
{
public:
    typedef double useless_type;
private:
    useless_type operator&() const;

	//useless_type operator reinterpret_cast<nonaddressable *> () const;
};
 
/*
int main(void)
{
  nonaddressable na;
  nonaddressable * naptr = &na; // Compiler error here.
 
  return 0;
}
*/

template <class T>
T * addressof(T & v)
{
  //return reinterpret_cast<T *>(& const_cast<char&>(reinterpret_cast<const volatile char &>(v)));
	return reinterpret_cast<T *>(& (reinterpret_cast<char &>(v)));
	//return reinterpret_cast<T *>(&(reinterpret_cast<char&>(v)));
}


int main(void)
{
  nonaddressable na;
  nonaddressable * naptr = addressof<nonaddressable>(na); // No more compiler error.
 
  return 0;
}
